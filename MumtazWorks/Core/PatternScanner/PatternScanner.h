#pragma once
#include <windows.h>
#include <cstdint>
#include <string_view>
#include <vector>
#include <optional>
#include <format>

class PatternScanner
{
public:
    struct Signature
    {
        std::string_view pattern{};
        std::string_view mask{};
    };

    explicit PatternScanner(const uintptr_t moduleBase = 0) noexcept
        : m_moduleBase(moduleBase)
        , m_moduleSize(0)
    {
        if (m_moduleBase == 0)
        {
            m_moduleBase = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
        }

        if (const auto module = reinterpret_cast<const IMAGE_DOS_HEADER*>(m_moduleBase); module && module->e_magic == IMAGE_DOS_SIGNATURE)
        {
            const auto ntHeaders = reinterpret_cast<const IMAGE_NT_HEADERS*>(m_moduleBase + static_cast<DWORD>(module->e_lfanew));
            if (ntHeaders && ntHeaders->Signature == IMAGE_NT_SIGNATURE)
            {
                m_moduleSize = ntHeaders->OptionalHeader.SizeOfImage;
            }
        }
    }

    [[nodiscard]] std::optional<uintptr_t> Scan(const Signature& sig) const noexcept
    {
        if (!m_moduleBase || !m_moduleSize || sig.pattern.empty())
            return std::nullopt;

        const auto bytes = reinterpret_cast<const unsigned char*>(m_moduleBase);
        const auto patternSize = sig.pattern.size();

        for (size_t i = 0; i <= m_moduleSize - patternSize; ++i)
        {
            bool found = true;
            for (size_t j = 0; j < patternSize && found; ++j)
            {
                if (sig.mask[j] != '?')
                {
                    found = (bytes[i + j] == static_cast<unsigned char>(sig.pattern[j]));
                }
            }
            if (found)
            {
                return m_moduleBase + i;
            }
        }

        return std::nullopt;
    }

    [[nodiscard]] std::optional<uintptr_t> Scan(std::string_view patternStr, std::string_view maskStr) const noexcept
    {
        return Scan(Signature{patternStr, maskStr});
    }

    [[nodiscard]] constexpr uintptr_t GetModuleBase() const noexcept { return m_moduleBase; }
    [[nodiscard]] constexpr uintptr_t GetModuleSize() const noexcept { return m_moduleSize; }

private:
    uintptr_t m_moduleBase;
    uintptr_t m_moduleSize;
};

namespace Pattern
{
    static int HexToChar(char c)
    {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        return 0;
    }

    // Helper to convert signature string like "48 8B ?? ?? ?? ?? C3" to pattern/mask
    inline PatternScanner::Signature Parse(std::string_view signature) noexcept
    {
        std::vector<unsigned char> pattern;
        std::string mask;

        size_t i = 0;
        while (i < signature.size())
        {
            if (signature[i] == ' ')
            {
                ++i;
                continue;
            }

            if (signature[i] == '?')
            {
                pattern.push_back(0);
                mask.push_back('?');
                if (i + 1 < signature.size() && signature[i + 1] == '?')
                    ++i;
            }
            else
            {
                pattern.push_back(static_cast<unsigned char>((HexToChar(signature[i]) << 4) | HexToChar(signature[i + 1])));
                mask.push_back('x');
                ++i;
            }
            ++i;
        }

        return {std::string_view(reinterpret_cast<const char*>(pattern.data()), pattern.size()), mask};
    }
}

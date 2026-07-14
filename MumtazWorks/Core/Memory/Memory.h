#pragma once
#include <windows.h>
#include <cstdint>

namespace Memory
{
    template <typename T>
    inline T Read(const uintptr_t address) noexcept
    {
        if (address == 0) return T{};
        return *reinterpret_cast<const T*>(address);
    }

    template <typename T>
    inline void Write(const uintptr_t address, const T& value) noexcept
    {
        if (address == 0) return;
        *reinterpret_cast<T*>(address) = value;
    }

    inline uintptr_t GetBaseAddress() noexcept
    {
        return reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
    }
}

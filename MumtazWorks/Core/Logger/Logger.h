#pragma once
#include <iostream>
#include <string_view>

namespace Logger
{
    inline void Info(std::string_view message) noexcept
    {
        std::cout << "[INFO] " << message << '\n';
    }

    inline void Warning(std::string_view message) noexcept
    {
        std::cout << "[WARNING] " << message << '\n';
    }

    inline void Error(std::string_view message) noexcept
    {
        std::cerr << "[ERROR] " << message << '\n';
    }
}

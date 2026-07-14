#pragma once
#include <windows.h>
#include <d3d9.h>

struct ImDrawData;

namespace ImGuiManager
{
    bool Initialize(HWND hwnd, IDirect3DDevice9* device) noexcept;
    void Shutdown() noexcept;
    void NewFrame(IDirect3DDevice9* device) noexcept;
    void Render() noexcept;
}

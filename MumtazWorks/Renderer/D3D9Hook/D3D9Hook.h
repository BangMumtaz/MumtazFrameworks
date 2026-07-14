#pragma once
#include <windows.h>
#include <d3d9.h>

// Forward declarations
struct IDirect3DDevice9;

namespace D3D9Hook
{
    bool Initialize() noexcept;
    void Shutdown() noexcept;
    void SetDevice(IDirect3DDevice9* device) noexcept;
    IDirect3DDevice9* GetDevice() noexcept;
    HWND GetOverlayWindow() noexcept;
}

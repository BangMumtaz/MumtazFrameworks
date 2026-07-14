#include "D3D9Hook.h"
#include "Core/Logger/Logger.h"

namespace D3D9Hook
{
    static IDirect3DDevice9* g_device = nullptr;
    static HWND g_overlayWindow = nullptr;

    bool Initialize() noexcept
    {
        Logger::Info("D3D9Hook::Initialize - stub for standalone testing");
        return true;
    }

    void Shutdown() noexcept
    {
        g_device = nullptr;
        g_overlayWindow = nullptr;
    }

    void SetDevice(IDirect3DDevice9* device) noexcept
    {
        g_device = device;
    }

    IDirect3DDevice9* GetDevice() noexcept
    {
        return g_device;
    }

    HWND GetOverlayWindow() noexcept
    {
        return g_overlayWindow;
    }
}

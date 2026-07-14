#include "ImGuiManager.h"
#include "Core/Logger/Logger.h"

namespace ImGuiManager
{
    bool Initialize(HWND hwnd, IDirect3DDevice9* device) noexcept
    {
        Logger::Info("ImGuiManager::Initialize - stub");
        return true;
    }

    void Shutdown() noexcept
    {
    }

    void NewFrame(IDirect3DDevice9* device) noexcept
    {
    }

    void Render() noexcept
    {
    }

    void RenderDrawData(ImDrawData* drawData) noexcept
    {
        (void)drawData;
    }
}

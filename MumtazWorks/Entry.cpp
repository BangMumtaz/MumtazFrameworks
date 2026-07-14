// Entry.cpp - MumtazWorks DLL Entry Point
#include <windows.h>
#include <memory>
#include "Core/Logger/Logger.h"
#include "Core/HookManager/HookManager.h"
#include "Core/PatternScanner/PatternScanner.h"

// Framework state
static bool g_frameworkLoaded = false;
static bool g_safetyHookStatus = false;
static bool g_patternScannerStatus = false;

BOOL APIENTRY DllMain(const HMODULE hModule, const DWORD ul_reason_for_call, LPVOID /*lpReserved*/) noexcept
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        Logger::Info("MumtazWorks DLL loaded");
        
        // Initialize HookManager (verifies SafetyHook compiles)
        g_safetyHookStatus = HookManager::Initialize();
        Logger::Info(g_safetyHookStatus ? "SafetyHook status: OK" : "SafetyHook status: FAILED");
        
        // Initialize PatternScanner
        PatternScanner scanner;
        g_patternScannerStatus = (scanner.GetModuleBase() != 0);
        Logger::Info(g_patternScannerStatus ? "PatternScanner status: OK" : "PatternScanner status: FAILED");
        
        g_frameworkLoaded = true;
        Logger::Info("MumtazWorks framework loaded");
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        Logger::Info("MumtazWorks DLL unloading");
        HookManager::Shutdown();
        Logger::Info("MumtazWorks framework shutdown complete");
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}

// Exported function to get framework status
extern "C" __declspec(dllexport) bool __cdecl MumtazWorks_IsLoaded()
{
    return g_frameworkLoaded;
}

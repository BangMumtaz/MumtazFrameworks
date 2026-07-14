
# OverlayTest — Build Complete ✅

**Audit of MumtazWorks**: The existing project is a DLL-based RE5 overlay using SafetyHook, a custom PatternScanner, a D3D9 hook (IDirect3DDevice9 vtable), and an ImGui renderer. **No existing framework code was modified.**

## OverlayTest Project Created

A **separate, standalone** Visual Studio 2022 project that validates ImGui + DirectX9 rendering independently from Resident Evil 5.

### Project Location
```
MumtazWorks/MumtazWorks/OverlayTest/
├── main.cpp                              ← Standalone Win32 + DX9 + ImGui app
├── OverlayTest.vcxproj                   ← Win32, Debug/Release, C++23 (/std:c++latest)
├── OverlayTest.vcxproj.filters
├── OverlayTest.vcxproj.user
└── deps/imgui/                           ← Dear ImGui v1.91.8 (vendored)
    ├── imgui.h, imgui.cpp, imgui_draw.cpp, imgui_tables.cpp, imgui_widgets.cpp
    ├── imgui_internal.h, imconfig.h, imstb_*.h
    └── backends/
        ├── imgui_impl_dx9.h / .cpp
        └── imgui_impl_win32.h / .cpp
```

### Build Output
```
bin\Debug\OverlayTest.exe   (Win32, Debug)
```

### What the App Does
1. Creates a **Win32 window** titled **"MumtazWorks Overlay Test"**
2. Initializes **DirectX9** (hardware vertex processing, vsync)
3. Initializes **Dear ImGui** with dark theme + DPI scaling
4. Renders a continuous ImGui window displaying:
   - **ImGui Initialized** status text
   - **DirectX9 Initialized** status text
   - **Frame Counter** (increments each frame)
   - **FPS** (`io.Framerate`)
   - `int BaseMap = 100` with `ImGui::InputInt("BaseMap", &BaseMap)`
   - **Increment** button that does `BaseMap += 1`

### Constraints Met
- ❌ No SafetyHook
- ❌ No PatternScanner
- ❌ No DLL injection
- ❌ No Resident Evil 5 integration
- ✅ Pure standalone Win32 + DirectX9 + Dear ImGui

### Build Command
```powershell
# From MumtazWorks/ directory:
& "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe" `
  "c:\Users\dwisa\source\repos\MumtazWorks\MumtazWorks.sln" `
  /p:Configuration=Debug /p:Platform=x86 /t:OverlayTest:Rebuild /v:minimal

# Or open the solution in VS2022 and build the OverlayTest project directly.
```

### Open the App
```
bin\Debug\OverlayTest.exe
```

#include "TestFeature.h"
#include "Core/Memory/Memory.h"
#include "Core/Logger/Logger.h"

TestFeature::TestFeature() noexcept
{
    Logger::Info("TestFeature::TestFeature - initialized");
}

void TestFeature::OnDraw() noexcept
{
    // Stub - ImGui integration pending
    Logger::Info("TestFeature::OnDraw called");
}

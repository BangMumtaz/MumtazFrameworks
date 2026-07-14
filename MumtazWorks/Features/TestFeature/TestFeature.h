#pragma once
#include "../IFeature/IFeature.h"

class TestFeature : public IFeature
{
public:
    TestFeature() noexcept;
    ~TestFeature() override = default;

    [[nodiscard]] const char* GetName() const noexcept override { return "TestFeature"; }
    [[nodiscard]] bool IsEnabled() const noexcept override { return m_enabled; }
    
    void OnDraw() noexcept override;
    void SetEnabled(bool enabled) noexcept { m_enabled = enabled; }

private:
    bool m_enabled = true;
    int m_testValue = 100;
};

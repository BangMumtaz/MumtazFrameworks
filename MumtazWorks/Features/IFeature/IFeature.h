#pragma once

class IFeature
{
public:
    virtual ~IFeature() = default;

    virtual const char* GetName() const noexcept = 0;
    virtual bool IsEnabled() const noexcept = 0;
    
    virtual void OnDraw() noexcept = 0;
    virtual void OnTick() noexcept {}
    virtual void OnPresent() noexcept {}
};

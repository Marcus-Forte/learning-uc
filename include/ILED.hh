#pragma once


class ILED {
    public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;
};
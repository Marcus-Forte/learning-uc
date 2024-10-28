#pragma once

#include "ILED.hh"
#include <gmock/gmock.h>

class MockILed : public ILED {
    public:
    MOCK_METHOD(void, on, (), (override));
    MOCK_METHOD(void, off, (), (override));
    MOCK_METHOD(void, toggle, (), (override));
};
#pragma once

#include "ITiming.hh"
#include <gmock/gmock.h>

class MockITiming : public ITiming {
    public:
    MOCK_METHOD(void, delay, (uint32_t), (override));
};
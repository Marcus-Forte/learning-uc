#pragma once

#include "IUART.hh"
#include <gmock/gmock.h>

class MockIUart : public IUART {
    public:
    MOCK_METHOD(void, write, (const std::string &msg), (override));
    MOCK_METHOD(std::string, read, (), (override));
};
#include <gtest/gtest.h>

#include "mocks/mock_led.hh"
#include "mocks/mock_timing.hh"
#include "mocks/mock_uart.hh"

using namespace testing;


#include "Module.hh"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test_module, test_module) {
    auto mockLED = std::make_shared<StrictMock<MockILed>>();
    auto mockUart =  std::make_shared<StrictMock<MockIUart>>();
    auto mockTiming =  std::make_shared<StrictMock<MockITiming>>();
    Module module(mockLED, mockUart, mockTiming);

    EXPECT_CALL(*mockLED, on());
    EXPECT_CALL(*mockTiming, delay(50)).Times(2);
    EXPECT_CALL(*mockLED, off());
    module.blink(50);

    EXPECT_CALL(*mockUart, write("msg!"));
    module.send("msg!");
}
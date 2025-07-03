#include "gmock/gmock.h"
#include "cal.cpp"

TEST(CalTest, TC1) {
    CAl cal;

    int ret = cal.getSum(10, 20);

    EXPECT_EQ(30, ret);
}
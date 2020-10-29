#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(AddTest, AddEvaluatePositive) {
    SevenPointFiveOpMock* value1 = new SevenPointFiveOpMock();
    SevenPointFiveOpMock* value2 = new SevenPointFiveOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), 15.0);
    EXPECT_EQ(add->stringify(), "15.000000");
}

TEST(AddTest, AddEvaluateNegativePlusZero) {
    NegativeSevenPointFiveOpMock* value1 = new NegativeSevenPointFiveOpMock();
    ZeroOpMock* value2 = new ZeroOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), -7.5);
    EXPECT_EQ(add->stringify(), "-7.500000");
}

TEST(AddTest, AddEvaluateNegativePlusNegative) {
    NegativeSevenPointFiveOpMock* value1 = new NegativeSevenPointFiveOpMock();
    NegativeSevenPointFiveOpMock* value2 = new NegativeSevenPointFiveOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), -15.0);
    EXPECT_EQ(add->stringify(), "-15.000000");
}

TEST(AddTest, AddEvaluateZeroPlusZero) {
    ZeroOpMock* value1 = new ZeroOpMock();
    ZeroOpMock* value2 = new ZeroOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), 0);
    EXPECT_EQ(add->stringify(), "0.000000");
}

TEST(AddTest, AddEvaluateLargePositiveNumbers) {
    OneThousandOpMock* value1 = new OneThousandOpMock();
    OneThousandOpMock* value2 = new OneThousandOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), 2000.0);
    EXPECT_EQ(add->stringify(), "2000.000000");
}

TEST(AddTest, AddEvaluateLargeNegativeNumbers) {
    NegativeOneThousandOpMock* value1 = new NegativeOneThousandOpMock();
    NegativeOneThousandOpMock* value2 = new NegativeOneThousandOpMock();

    Add* add = new Add(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(add->evaluate(), -2000.0);
    EXPECT_EQ(add->stringify(), "-2000.000000");
}

TEST(SubTest, SubEvaluatePositive) {
    OneThousandOpMock* value1 = new OneThousandOpMock();
    SevenPointFiveOpMock* value2 = new SevenPointFiveOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), 992.5);
    EXPECT_EQ(sub->stringify(), "992.500000");
}

TEST(SubTest, SubEvaluateNegative) {
    SevenPointFiveOpMock* value1 = new SevenPointFiveOpMock();
    OneThousandOpMock* value2 = new OneThousandOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), -992.5);
    EXPECT_EQ(sub->stringify(), "-992.500000");
}

TEST(SubTest, SubEvaluateNumMinusZero) {
    SevenPointFiveOpMock* value1 = new SevenPointFiveOpMock();
    ZeroOpMock* value2 = new ZeroOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), 7.5);
    EXPECT_EQ(sub->stringify(), "7.500000");
}

TEST(SubTest, SubEvaluateZeroMinusNum) {
    ZeroOpMock* value1 = new ZeroOpMock();
    OneThousandOpMock* value2 = new OneThousandOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), -1000);
    EXPECT_EQ(sub->stringify(), "-1000.000000");
}

TEST(SubTest, SubEvaluateNegativeMinusNegative) {
    NegativeOneThousandOpMock* value1 = new NegativeOneThousandOpMock();
    NegativeSevenPointFiveOpMock* value2 = new NegativeSevenPointFiveOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), -992.5);
    EXPECT_EQ(sub->stringify(), "-992.500000");
}

TEST(SubTest, SubEvaluateNegativeMinusPositive) {
    NegativeOneThousandOpMock* value1 = new NegativeOneThousandOpMock();
    OneThousandOpMock* value2 = new OneThousandOpMock();

    Sub* sub = new Sub(value1->evaluate(), value2->evaluate());
    EXPECT_EQ(sub->evaluate(), -2000);
    EXPECT_EQ(sub->stringify(), "-2000.000000");
}

#endif //__TEST_HPP__
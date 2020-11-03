#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(AddTest, AddEvaluatePositive) {
    Base* SevenPointFiveOp = new Op(7.5);

    Base* add = new Add(SevenPointFiveOp, SevenPointFiveOp);
    EXPECT_EQ(add->evaluate(), 15.0);
    EXPECT_EQ(add->stringify(), "7.500000 + 7.500000");
}

TEST(AddTest, AddEvaluateNegativePlusZero) {
    Base* NegativeSevenPointFiveOp = new Op(-7.5);
    Base* ZeroOp = new Op(0);

    Base* add = new Add(NegativeSevenPointFiveOp, ZeroOp);
    EXPECT_EQ(add->evaluate(), -7.5);
    EXPECT_EQ(add->stringify(), "-7.500000 + 0.000000");
}

TEST(AddTest, AddEvaluateNegativePlusNegative) {
    Base* NegativeSevenPointFiveOp = new Op(-7.5);

    Base* add = new Add(NegativeSevenPointFiveOp, NegativeSevenPointFiveOp);
    EXPECT_EQ(add->evaluate(), -15.0);
    EXPECT_EQ(add->stringify(), "-7.500000 + -7.500000");
}

TEST(AddTest, AddEvaluateZeroPlusZero) {
    Base* ZeroOp = new Op(0);

    Base* add = new Add(ZeroOp, ZeroOp);
    EXPECT_EQ(add->evaluate(), 0);
    EXPECT_EQ(add->stringify(), "0.000000 + 0.000000");
}

TEST(AddTest, AddEvaluateLargePositiveNumbers) {
    Base* OneThousandOp = new Op(1000);

    Base* add = new Add(OneThousandOp, OneThousandOp);
    EXPECT_EQ(add->evaluate(), 2000.0);
    EXPECT_EQ(add->stringify(), "1000.000000 + 1000.000000");
}

TEST(AddTest, AddEvaluateLargeNegativeNumbers) {
    Base* NegativeOneThousandOp = new Op(-1000);

    Base* add = new Add(NegativeOneThousandOp, NegativeOneThousandOp);
    EXPECT_EQ(add->evaluate(), -2000.0);
    EXPECT_EQ(add->stringify(), "-1000.000000 + -1000.000000");
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
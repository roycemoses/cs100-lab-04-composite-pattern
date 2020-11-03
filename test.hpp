#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"

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
    Base* oneThousandOp = new Op(1000);
    Base* sevenPointFiveOp = new Op(7.5);

    Base* sub = new Sub(oneThousandOp, sevenPointFiveOp);
    EXPECT_EQ(sub->evaluate(), 992.5);
    EXPECT_EQ(sub->stringify(), "1000.000000 - 7.500000");
}

TEST(SubTest, SubEvaluateNegative) {
    Base* sevenPointFiveOp = new Op(7.5);
    Base* oneThousandOp = new Op(1000);

    Base* sub = new Sub(sevenPointFiveOp, oneThousandOp);
    EXPECT_EQ(sub->evaluate(), -992.5);
    EXPECT_EQ(sub->stringify(), "7.500000 - 1000.000000");
}

TEST(SubTest, SubEvaluateNumMinusZero) {
    Base* sevenPointFiveOp = new Op(7.5);
    Base* zeroOp = new Op(0);

    Base* sub = new Sub(sevenPointFiveOp, zeroOp);
    EXPECT_EQ(sub->evaluate(), 7.5);
    EXPECT_EQ(sub->stringify(), "7.500000 - 0.000000");
}

TEST(SubTest, SubEvaluateZeroMinusNum) {
    Base* zeroOp = new Op(0);
    Base* oneThousandOp = new Op(1000);

    Base* sub = new Sub(zeroOp, oneThousandOp);
    EXPECT_EQ(sub->evaluate(), -1000);
    EXPECT_EQ(sub->stringify(), "0.000000 - 1000.000000");
}

TEST(SubTest, SubEvaluateNegativeMinusNegative) {
    Base* negativeOneThousandOp = new Op(-1000);
    Base* negativeSevenPointFiveOp = new Op(-7.5);

    Base* sub = new Sub(negativeOneThousandOp, negativeSevenPointFiveOp);
    EXPECT_EQ(sub->evaluate(), -992.5);
    EXPECT_EQ(sub->stringify(), "-1000.000000 - -7.500000");
}

TEST(SubTest, SubEvaluateNegativeMinusPositive) {
    Base* negativeOneThousandOp = new Op(-1000);
    Base* oneThousandOp = new Op(1000);

    Base* sub = new Sub(negativeOneThousandOp, oneThousandOp);
    EXPECT_EQ(sub->evaluate(), -2000);
    EXPECT_EQ(sub->stringify(), "-1000.000000 - 1000.000000");
}

TEST(MultTest, MultEvaluatePositiveTimesPositive) {
    Base* nineteenOp = new Op(19);
    
    Base* mult = new Mult(nineteenOp, nineteenOp);
    EXPECT_EQ(mult->evaluate(), 361);
    EXPECT_EQ(mult->stringify(), "19.000000 * 19.000000");
}

TEST(MultTest, MultEvaluatePositiveTimesNegative) {
    Base* nineteenOp = new Op(19);
    Base* negativeTwoOp = new Op(-2);
    
    Base* mult = new Mult(nineteenOp, negativeTwoOp);
    EXPECT_EQ(mult->evaluate(), -38);
    EXPECT_EQ(mult->stringify(), "19.000000 * -2.000000");
}

TEST(MultTest, MultEvaluateNegativeTimesNegative) {
    Base* negativeNineteenOp = new Op(-19);
    Base* negativeTwoOp = new Op(-2);
    
    Base* mult = new Mult(negativeNineteenOp, negativeTwoOp);
    EXPECT_EQ(mult->evaluate(), 38);
    EXPECT_EQ(mult->stringify(), "-19.000000 * -2.000000");
}

TEST(MultTest, MultEvaluateZeroTimesNum) {
    Base* zeroOp = new Op(0);
    Base* twoOp = new Op(2);
    
    Base* mult = new Mult(zeroOp, twoOp);
    EXPECT_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "0.000000 * 2.000000");
}

#endif //__TEST_HPP__
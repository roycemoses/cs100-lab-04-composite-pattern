#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Base* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Base* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative) {
    Base* test = new Op(-8);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpEvaluateLargeNumber) {
    Base* test = new Op(999.999);
    EXPECT_EQ(test->evaluate(), 999.999);
}

TEST(OpTest, OpEvaluateNegativeLargeNumber) {
    Base* test = new Op(-999.999);
    EXPECT_EQ(test->evaluate(), -999.999);
}

TEST(OpTest, OpEvaluateSmallNumber) {
    Base* test = new Op(0.0001);
    EXPECT_EQ(test->evaluate(), 0.0001);
}

TEST(OpTest, OpEvaluateNegativeSmallNumber) {
    Base* test = new Op(-0.0001);
    EXPECT_EQ(test->evaluate(), -0.0001);
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

TEST(AddTest, AddEvaluateSub) {
    Base* fiveOp = new Op(5);
    Base* tenOp = new Op(10);

    Base* sub = new Sub(tenOp, fiveOp);
    Base* add = new Add(fiveOp, sub);
    EXPECT_EQ(add->evaluate(), 10);
    EXPECT_EQ(add->stringify(), "5.000000 + 10.000000 - 5.000000");
}

TEST(AddTest, AddEvaluateNegativeSub) {
    Base* fiveOp = new Op(5);
    Base* tenOp = new Op(10);

    Base* sub = new Sub(fiveOp, tenOp);
    Base* add = new Add(tenOp, sub);
    EXPECT_EQ(add->evaluate(), 5);
    EXPECT_EQ(add->stringify(), "10.000000 + 5.000000 - 10.000000");
}

TEST(AddTest, AddEvaluateMult) {
    Base* sevenOp = new Op(7);
    Base* eightOp = new Op(8);

    Base* mult = new Mult(sevenOp, eightOp);
    Base* add = new Add(sevenOp, mult);
    EXPECT_EQ(add->evaluate(), 63);
    EXPECT_EQ(add->stringify(), "7.000000 + 7.000000 * 8.000000");
}

TEST(AddTest, AddEvaluateNegativeMult) {
    Base* sevenOp = new Op(7);
    Base* negativeEightOp = new Op(-8);

    Base* mult = new Mult(sevenOp, negativeEightOp);
    Base* add = new Add(sevenOp, mult);
    EXPECT_EQ(add->evaluate(), -49);
    EXPECT_EQ(add->stringify(), "7.000000 + 7.000000 * -8.000000");
}

TEST(AddTest, AddEvaluateDiv) {
    Base* fortyFiveOp = new Op(45);
    Base* fiveOp = new Op(5);

    Base* div = new Div(fortyFiveOp, fiveOp);
    Base* add = new Add(fiveOp, div);
    EXPECT_EQ(add->evaluate(), 14);
    EXPECT_EQ(add->stringify(), "5.000000 + 45.000000 / 5.000000");
}

TEST(AddTest, AddEvaluateNegativeDiv) {
    Base* fortyFiveOp = new Op(45);
    Base* negativeFiveOp = new Op(-5);

    Base* div = new Div(fortyFiveOp, negativeFiveOp);
    Base* add = new Add(negativeFiveOp, div);
    EXPECT_EQ(add->evaluate(), -14);
    EXPECT_EQ(add->stringify(), "-5.000000 + 45.000000 / -5.000000");
}

TEST(AddTest, AddEvaluatePow) {
    Base* twoOp = new Op(2);
    Base* threeOp = new Op(3);

    Base* pow = new Pow(twoOp, threeOp);
    Base* add = new Add(threeOp, pow);
    EXPECT_EQ(add->evaluate(), 11);
    EXPECT_EQ(add->stringify(), "3.000000 + 2.000000 ** 3.000000");
}

TEST(AddTest, AddEvaluateNegativePow) {
    Base* twoOp = new Op(2);
    Base* negativeThreeOp = new Op(-3);

    Base* pow = new Pow(twoOp, negativeThreeOp);
    Base* add = new Add(negativeThreeOp, pow);
    EXPECT_EQ(add->evaluate(), -2.875);
    EXPECT_EQ(add->stringify(), "-3.000000 + 2.000000 ** -3.000000");
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

TEST(SubTest, SubEvaluateMult) {
    Base* fiveOp = new Op(5);
    Base* eightOp = new Op(8);

    Base* mult = new Mult(fiveOp, eightOp);
    Base* sub = new Sub(fiveOp, mult);
    EXPECT_EQ(sub->evaluate(), -35);
    EXPECT_EQ(sub->stringify(), "5.000000 - 5.000000 * 8.000000");
}

TEST(SubTest, SubEvaluateNegativeMult) {
    Base* fiveOp = new Op(5);
    Base* negativeEightOp = new Op(-8);

    Base* mult = new Mult(fiveOp, negativeEightOp);
    Base* sub = new Sub(fiveOp, mult);
    EXPECT_EQ(sub->evaluate(), 45);
    EXPECT_EQ(sub->stringify(), "5.000000 - 5.000000 * -8.000000");
}

TEST(SubTest, SubEvaluateDiv) {
    Base* threeOp = new Op(3);
    Base* thirtyThreeOp = new Op(33);

    Base* div = new Div(thirtyThreeOp, threeOp);
    Base* sub = new Sub(threeOp, div);
    EXPECT_EQ(sub->evaluate(), -8);
    EXPECT_EQ(sub->stringify(), "3.000000 - 33.000000 / 3.000000");
}

TEST(SubTest, SubEvaluateNegativeDiv) {
    Base* negativeThreeOp = new Op(-3);
    Base* thirtyThreeOp= new Op(33);

    Base* div = new Div(thirtyThreeOp, negativeThreeOp);
    Base* sub = new Sub(negativeThreeOp, div);
    EXPECT_EQ(sub->evaluate(), 8);
    EXPECT_EQ(sub->stringify(), "-3.000000 - 33.000000 / -3.000000");
}

TEST(SubTest, SubEvaluatePow) {
    Base* twoOp = new Op(2);
    Base* fiveOp = new Op(5);

    Base* pow = new Pow(twoOp, fiveOp);
    Base* sub = new Sub(twoOp, pow);
    EXPECT_EQ(sub->evaluate(), -30);
    EXPECT_EQ(sub->stringify(), "2.000000 - 2.000000 ** 5.000000");
}

TEST(SubTest, SubEvaluateNegativePow) {
    Base* negativeTwoOp = new Op(-2);
    Base* fiveOp = new Op(5);

    Base* pow = new Pow(negativeTwoOp, fiveOp);
    Base* sub = new Sub(negativeTwoOp, pow);
    EXPECT_EQ(sub->evaluate(), 30);
    EXPECT_EQ(sub->stringify(), "-2.000000 - -2.000000 ** 5.000000");
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

TEST(MultTest, MultEvaluateZeroTimesZero) {
    Base* zeroOp = new Op(0);
    
    Base* mult = new Mult(zeroOp, zeroOp);
    EXPECT_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "0.000000 * 0.000000");
}

TEST(MultTest, MultEvaluateLargePositiveNum) {
    Base* oneThousandOp = new Op(1000);
    
    Base* mult = new Mult(oneThousandOp, oneThousandOp);
    EXPECT_EQ(mult->evaluate(), 1000000);
    EXPECT_EQ(mult->stringify(), "1000.000000 * 1000.000000");
}

TEST(MultTest, MultEvaluateDiv) {
    Base* twentyOp = new Op(20);
    Base* twoOp = new Op(2);
    
    Base* div = new Div(twentyOp, twoOp);
    Base* mult = new Mult(twentyOp, div);
    EXPECT_EQ(mult->evaluate(), 200);
    EXPECT_EQ(mult->stringify(), "20.000000 * 20.000000 / 2.000000");
}


TEST(DivTest, DivEvaluatePositive) {
    Base* nineOp = new Op(9);
    Base* threeOp = new Op(3);

    Base* div = new Div(nineOp, threeOp);
    EXPECT_EQ(div->evaluate(), 3);
    EXPECT_EQ(div->stringify(), "9.000000 / 3.000000");
}

TEST(DivTest, DivEvaluateNegative) {
    Base* negativeNineOp = new Op(-9);
    Base* threeOp = new Op(3);

    Base* div = new Div(negativeNineOp, threeOp);
    EXPECT_EQ(div->evaluate(), -3);
    EXPECT_EQ(div->stringify(), "-9.000000 / 3.000000");
}

#endif //__TEST_HPP__
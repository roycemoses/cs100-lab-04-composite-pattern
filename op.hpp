#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private:
        double value;
    public:
        Op(double value) : value(value), Base() { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(evaluate()); }
};

class SevenPointFiveOpMock: public Base {
    public:
        SevenPointFiveOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { };

        virtual double evaluate() { return 0; }
        virtual std::string stringify() { return "0"; }
};

class NegativeSevenPointFiveOpMock: public Base {
    public:
        NegativeSevenPointFiveOpMock() { };

        virtual double evaluate() { return -7.5; }
        virtual std::string stringify() { return "-7.5"; }
};

class OneThousandOpMock: public Base {
    public:
        OneThousandOpMock() { };

        virtual double evaluate() { return 1000; }
        virtual std::string stringify() { return "1000"; }
};

class NegativeOneThousandOpMock: public Base {
    public:
        NegativeOneThousandOpMock() { };

        virtual double evaluate() { return -1000; }
        virtual std::string stringify() { return "-1000"; }
};

#endif //__OP_HPP__
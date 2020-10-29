#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
        double value1;
        double value2;
    public:
        Sub(double value1, double value2) : value1(value1), value2(value2), Base() { }
        virtual double evaluate() { return value1 - value2; }
        virtual std::string stringify() { return std::to_string(evaluate()); }
};

#endif // __SUB_HPP__
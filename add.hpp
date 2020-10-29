#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
    private:
        double value1;
        double value2;
    public:
        Add(double value1, double value2) : value1(value1), value2(value2), Base() { }
        virtual double evaluate() { return value1 + value2; }
        virtual std::string stringify() { return std::to_string(evaluate()); }
};

#endif // __ADD_HPP__
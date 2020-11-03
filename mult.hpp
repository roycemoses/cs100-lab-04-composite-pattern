#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Mult(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { }
        virtual double evaluate() { return value1->getValue() * value2->getValue(); }
};

#endif // __MULT_HPP__
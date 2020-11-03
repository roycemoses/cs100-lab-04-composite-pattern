#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Sub(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { setValue(evaluate()); }
        virtual double evaluate() { return value1->getValue() - value2->getValue(); }
        virtual std::string stringify() { return std::to_string(value1->getValue()) + " - " + std::to_string(value2->getValue()); }
};

#endif // __SUB_HPP__
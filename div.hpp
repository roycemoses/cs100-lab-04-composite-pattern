#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Div(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { }
        virtual double evaluate() { }
        virtual std::string stringify() { }
};

#endif // __DIV_HPP__
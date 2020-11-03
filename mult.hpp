#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Mult(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { }
};

#endif // __MULT_HPP__
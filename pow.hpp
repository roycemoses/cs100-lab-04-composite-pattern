#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

class Pow : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Pow(Base* value1, Base* value2) : value1(value1), value2(value2), Base() {  }
        virtual double evaluate() {  }
        virtual std::string stringify() { }
};

#endif // __POW_HPP__
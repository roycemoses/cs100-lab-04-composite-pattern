#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

class Pow : public Base {
    private:
        Base* base;
        Base* power;
    public:
        Pow(Base* base, Base* power) : base(base), power(power), Base() {  }
        virtual double evaluate() { }
        virtual std::string stringify() { }
};

#endif // __POW_HPP__
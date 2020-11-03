#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand() : Base() { this->setValue(rand() % 100); }
        virtual double evaluate() { return this->getValue(); }
};

#endif //__RAND_HPP__
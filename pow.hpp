#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

class Pow : public Base {
    private:
        Base* base;
        Base* power;
    public:
        Pow(Base* base, Base* power) : base(base), power(power), Base() { this->setValue(evaluate()); }
        virtual double evaluate()
        {
            double result = 1;          // result starts at 1

            if (power->getValue() < 0)  // if negative power
            {
                double positive_power = power->getValue() * -1;         // number of times to divide (magnitude of power)
                for (unsigned int i = 0; i < positive_power; ++i)
                    result /= base->getValue();
            }
            else                        // if zero or positive power
            {
                for (unsigned int i = 0; i < power->getValue(); ++i)    // number of times to multiply
                    result *= base->getValue();
            }
            return result;
        }
        virtual std::string stringify() { return base->stringify() + std::string(" ** ") + power->stringify(); }
};

#endif // __POW_HPP__
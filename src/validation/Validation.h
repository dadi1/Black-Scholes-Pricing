#ifndef VALIDATION_H
#define VALIDATION_H

#include <typeinfo>
#include <stdexcept>

namespace validation
{
    void validation_double_bsm(double Spot,
                               double Strike,
                               double r,
                               double d,
                               double Vol,
                               double Expiry);
}

#endif
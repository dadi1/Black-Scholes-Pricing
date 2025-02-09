#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdexcept>

namespace validatoin
{
    void validation_double_bsm(double Spot,
                               double Strike,
                               double r,
                               double d,
                               double Vol,
                               double Expiry);
}

#endif
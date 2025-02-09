#include "Validation.h"

namespace validaton
{
    void validation_double_bsm(double Spot,
                               double Strike,
                               double r,
                               double d,
                               double Vol,
                               double Expiry)
    {
        if (typeid(Spot) != typeid(double))
            throw std::invalid_argument("Spot parameter is not a Number");
        
        if (typeid(Strike) != typeid(double))
            throw std::invalid_argument("Strike parameter is not a Number");
        
        if (typeid(r) != typeid(double))
            throw std::invalid_argument("r parameter is not a Number");
        
        if (typeid(d) != typeid(double))
            throw std::invalid_argument("d parameter ir not a Number");
        
        if (typeid(Vol) != typeid(double))
            throw std::invalid_argument("Vol parameter is not a Number");
        
        if (typeid(Expiry) != typeid(double))
            throw std::invalid_argument("Expiry parameters is not Number");
    }
}
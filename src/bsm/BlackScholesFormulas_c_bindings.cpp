/**
 * @file BlackScholesFormulas_c_bindings.cpp
 * @author Narayan Shimanoe Lisboa
 * @date 29/01/2025
 * 
 * @brief Source File implemetation of Black-Scholes functions in ctypes for Python.
 * 
 */

#include "BlackScholesFormulas.h"

extern "C" {

    // BlackScholesCall() for ctypes.
    double BlackScholesCall_c( double Spot,
                               double Strike,
                               double r,
                               double d,
                               double Vol,
                               double Expiry)
    {
        BlackScholesCall(Spot, Strike, r, d, Vol, Expiry);
    }

    // Function for Put Option.
    double BlackScholesPut_c( double Spot,
                              double Strike,
                              double r,
                              double d,
                              double Vol,
                              double Expiry)
    {
        BlackScholesPut(Spot, Strike, r, d, Vol, Expiry);
    }

    // BlackScholesDigitalCall() for ctypes.
    double BlackScholesDigitalCall_c( double Spot,
                                      double Strike,
                                      double r,
                                      double d,
                                      double Vol,
                                      double Expiry)
    {
        BlackScholesDigitalCall(Spot, Strike, r, d, Vol, Expiry);
    }

    // BlackScholesCallVeega() for ctypes.
    double BlackScholesCallVega_c( double Spot,
                                   double Strike,
                                   double r,
                                   double d,
                                   double Vol,
                                   double Expiry)
    {
        BlackScholesCallVega(Spot, Strike, r, d, Vol, Expiry);
    }

}
/**
 * @file BlackScholesFormulas.cpp
 * @author Narayan Shimanoe Lisboa
 * @date 28/01/2025
 * 
 * @brief Souce File implemetation of Black-Scholes function for pricing derivatives
 */

/**
 * @param Spot - Current price of the underlying asset.
 * @param Strike - Strike price of the derivative.
 * @param r - Annual risk-free rate.
 * @param d -   Annual dividend yield of the underlyin asset.
 * @param Vol - Annual Volatility of the underlying asset.
 * @param Expiry - Expiry time of the asset in years.
 *
 * @return double - The price of the asset.
 * 
 */

#include "BlackScholesFormulas.h"
#include "../normals/Normals.h"
#include <cmath>
#include "../validation/Validation.h"

// Function for Call Option.
double BlackScholesCall(double Spot,
                        double Strike,
                        double r,
                        double d,
                        double Vol,
                        double Expiry)
{
    // Defense programming.
    validation::validation_double_bsm(Spot,
                                      Strike,
                                      r,
                                      d,
                                      Vol,
                                      Expiry);
    // BlackScholesCall implematation.

    double standardDeviation = Vol * std::sqrt(Expiry);
    double moneyNess = std::log(Spot / Strike);
    double d1 = (moneyNess + (r - d) * Expiry +
        0.5 * standardDeviation * standardDeviation) / standardDeviation;
    double d2 = d1 - standardDeviation;

    return Spot * std::exp(-d * Expiry) * CumulativeNormal(d1) -
        Strike * std::exp(-r * Expiry) * CumulativeNormal(d2);
}

// Function for Put Option.
double BlackScholesPut(double Spot,
                       double Strike,
                       double r,
                       double d,
                       double Vol,
                       double Expiry)
{
    // Defense programming.
    validation::validation_double_bsm(Spot,
                                      Strike,
                                      r,
                                      d,
                                      Vol,
                                      Expiry);

    // BlackScholesPut implemetation.
    double standardDeviation = Vol * std::sqrt(Expiry);
    double moneyNess = std::log(Spot / Strike);
    double d2 = (moneyNess + (r - d) * Expiry -
        0.5 * standardDeviation * standardDeviation) / standardDeviation;
    
    return std::exp(-r * Expiry) * CumulativeNormal(d2);
}

// Function for Digital Call Option.
double BlackScholesDigitalCall(double Spot,
                              double Strike,
                              double r,
                              double d,
                              double Vol,
                              double Expiry)
{
    // Defense programming.
    validation::validation_double_bsm(Spot,
                                      Strike,
                                      r,
                                      d,
                                      Vol,
                                      Expiry);

    // BlackScholesDigitalCall Implemetation.
    double standardDeviation = Vol * std::sqrt(Expiry);
    double moneyNess = std::log(Spot / Strike);
    double d2 = (moneyNess + (r - d) * Expiry - 
        0.5 * standardDeviation * standardDeviation) / standardDeviation;
    
    return std::exp(-r * Expiry) * (1.0 - CumulativeNormal(d2));
}

// Function for Call Vega Option.
double BlackScholesCallVega(double Spot,
                            double Strike,
                            double r,
                            double d,
                            double Vol,
                            double Expiry)
{
    // Defense programming.
    validation::validation_double_bsm(Spot,
                                      Strike,
                                      r,
                                      d,
                                      Vol,
                                      Expiry);

    // BlackScholesCallVega Implematation.
    double standardDeviation = Vol * std::sqrt(Expiry);
    double moneyNess = std::log(Spot / Strike);
    double d1 = (moneyNess + (r - d) * Expiry + 
        0.5 * standardDeviation + standardDeviation) / standardDeviation;
    
    return Spot * std::exp(-d * Expiry) * std::sqrt(Expiry) * NormalDensity(d1);
}


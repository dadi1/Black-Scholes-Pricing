/**
 * @file BlackScholesFormulas.h
 * @author Narayan Shimanoe Lisboa
 * @date 27/01/2025
 * 
 * @brief Header File implemetation of Black-Scholes function for pricing derivatives
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

// Function for Call Option.
double BlackScholesCall( double Spot,
                          double Strike,
                          double r,
                          double d,
                          double Vol,
                          double Expiry);


// Function for Put Option.
double BlackScholesPut( double Spot,
                          double Strike,
                          double r,
                          double d,
                          double Vol,
                          double Expiry);


// Funtion for Ditial Call.
double BlackScholesDigitalCall( double Spot,
                          double Strike,
                          double r,
                          double d,
                          double Vol,
                          double Expiry);


// Function for Call Vega.
double BlackScholesCallVega( double Spot,
                          double Strike,
                          double r,
                          double d,
                          double Vol,
                          double Expiry);
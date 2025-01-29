/**
 * 
 *  File for Testis Black-Scholes formulas implemented in BlackScholesFormulas.h
 *  In BlackScholesFormulas.h:
 *  - BlackScholesCall()
 *  - BlackScholesPut()
 *  - BlackScholesDigitalCall()
 *  - BlackScholesCallVega()
 * 
 *  In the Tests the Pattern of the Parameters is:
 *  Spot Price = 100 USD
 *  Strike Price = 110 USD
 *  r = 0.01 (1%),
 *  d = 0.02 (2%),
 *  Vol = 0.2 (20%),
 *  Expiry = 2 Yeas
 *
 */

#include "../src/bsm/BlackScholesFormulas.h"
#include <iostream>

int main() 
{
    // for function BlackScholesCall():
    std::cout << "BlackScholesCall() function test: " << std::endl;
    std::cout << "for Spot = 100, Strike = 110, r = 0.01, d = 0.02, Vol = 0.2, Expiry = 1" << std::endl;
    std::cout << "result is: " <<  BlackScholesCall(100, 110, 0.01, 0.02, 0.2, 1) << std::endl;

    // for function BlackScholesPut():
    std::cout << "BalckScholesPut() function test: " << std::endl;
    std::cout << "for Spot = 100, Strike = 110, r = 0.01, d = 0.02, Vol = 0.2, Expiry = 1" << std::endl;
    std::cout << "result is: " << BlackScholesPut(100, 110, 0.01, 0.02, 0.2, 1) << std::endl;
    
    
    
    
    return 0;
}
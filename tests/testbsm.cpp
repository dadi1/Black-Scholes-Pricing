/**
 * 
 *  File for Testis Black-Scholes formulas implemented in BlackScholesFormulas.h
 *  In BlackScholesFormulas.h:
 *  - BlackScholesCall()
 *  - BlackScholesPut()
 *  - BlackScholesDigitalCall()
 *  - BlackScholesCallVega()
 *
 */

#include "../src/bsm/BlackScholesFormulas.h"
#include <iostream>

int main() 
{
    // for cuntion BlackScholesCall():
    std::cout << "BlackScholesCall() function test: " << std::endl;
    std::cout << "for Spot = 20.34, Strike = 21.1, r = 0.04, d = 0.03, Vol = 2.334, Expiry = 9" << std::endl;
    std::cout << "result is: " <<  BlackScholesCall(20.34, 21.1, 0.04, 0.03, 2.334, 9) << std::endl;

    return 0;
}
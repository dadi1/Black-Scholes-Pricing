/**
 * 
 *  File for testing all three functin impleneteds
 *  In Normals.h:
 *  - NormalDensity(double x)
 *  - CumulativeNormal(double x)
 *  - InverseCumulativeNormal(double x)
 */

#include "../src/normals/Normals.h"
#include <iostream>

int main()
{
    // test for NormalDensity(double x) function:
    std::cout << "NormalDensity(x) are: " << std::endl;
    std:: cout << NormalDensity(-30.3) << " " << NormalDensity(0) << " " << NormalDensity(30.3) << std::endl;

    return 0;
}
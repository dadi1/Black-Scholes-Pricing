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
    std:: cout << "tested x = -30.3: " << NormalDensity(-30.3) << ", tested for x = 0: " << NormalDensity(0) << ", tested for x = 30.3: " <<
    NormalDensity(30.3) << std::endl;


    //test for InverseCumulativeNormal(double x) function:
    std::cout << "InverseCumulativeNormal(double x) function are: " << std::endl;
    std::cout << "tested for x = 0.43: " << InverseCumulativeNormal(0.43) << ", tested for x = 0.41: " << InverseCumulativeNormal(0.41) << ", tested for x = 0.88: " << InverseCumulativeNormal(0.088) << std::endl;

    //test for CumulativeNormal(double x) function:
    std::cout << "CumulativeNormal(double x) function are:";
    std::cout << "tested for x = 7.2: " << CumulativeNormal(7.2) << std::endl;
    std::cout << "tested for x = 5.3: " << CumulativeNormal(5.3) << std::endl;
    std::cout << "tested for x = -7.1: " << CumulativeNormal(-7.1) << std::endl;
    std::cout << "tested for x = -5.3: " <<CumulativeNormal(-5.3) << std::endl;

    return 0;
}
"""
Test file for testing the function in 
BlackScholesFormulas.h implemented in C++ 
for Python code
"""


import ctypes # Importing the library for using C++


"""
Test for BlackScholesCall() function
with parameters:
    Spot = 100
    Strike = 110
    r = 0.01
    d = 0.02
    volatility = 0.2
    Time = 1
    """
"""
BlackScholesCall = ctypes.CDLL("./libtest.so").BlackScholesCall_c

BlackScholesCall.restype = None
BlackScholesCall.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double]
BlackScholesCall.restype = ctypes.c_double

print(BlackScholesCall(100.0, 110.0, 0.01, 0.02, 0.2, 1.0)) """

"""

Test for BlackScholesPut() function
with parameters:
    Spot = 100
    Strike = 110
    r = 0.01
    d = 0.02
    volatility = 0.2
    Time = 1
    """
BlackScholesPut = ctypes.CDLL("./libtest.so").BlackScholesPut_c

BlackScholesPut.restype = None
BlackScholesPut.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double]
BlackScholesPut.restype = ctypes.c_double
print(BlackScholesPut(100.0, 110.0, 0.01, 0.02, 0.2, 1.0))
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
libtest = ctypes.CDLL("./libtest.so").BlackScholesCall_c

libtest.restype = None
libtest.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double]
libtest.restype = ctypes.c_double

print(libtest(100.0, 110.0, 0.01, 0.02, 0.2, 1.0))

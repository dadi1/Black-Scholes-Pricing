import os
import sys
import ctypes

LIBRARY_NAME = blackscholesdd.so

if sys.platform.startswith("win"):
    LIBRARY_NAME += ".dll"
elif sys.platform == "darwin":
    LIBRARY_NAME += ".dylib"
else:
    LIBRARY_NAME += ".so"

LIBRARY_PATH = os.path.join(os.path.dirname(__file__), LIBRARY_NAME)

try:
    lib = ctypes.CDLL(LIBRARY_PATH)
except OSError as e:
    raise RuntimeError(f"Fail to lead the library: {e}")
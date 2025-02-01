import os
import ctypes

LIBRARY_PATH = os.path.join(os.path.dirname(__file__), blackscholesdd.so)
lib = ctypes.CDLL(LIBRARY_PATH)

def main():
    print("welcome to the libray")

if __name__ == "__main__":
    main()
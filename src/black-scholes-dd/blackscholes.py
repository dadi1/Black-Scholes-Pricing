import numpy as np

# Defining constants

E = np.e # Euler's constant
T = 1 # One year of pricing
N = 30 # Trading day with
dt = T / N
Tau = T * ()

def black_scholes(S , K, T, r, sigma):
    """
    Calculate the price a derivative using Blach-Scholes model
    
    Parameters:
    - S: float - price of a underlying asset
    - K: float - strike price
    - T: float - time of the asset maturity
    - r: float - risk-free rate
    - sigma: float - underlying asset volatility
    
    Return:
    - V: float -
    - d1: float - 
    - d2: float - 
    """
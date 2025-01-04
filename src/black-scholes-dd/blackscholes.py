import numpy as np
from scipy.stats import norm

# Defining constants

E = np.e # Euler's constant
T = 1 # One year of pricing
N = 30 # Trading day with
dt = T / N
Tau = T * (np.ones(N) - dt * np.arange(N))

def black_scholes(S , K, r, sigma, Tau):
    """
    Calculate the price a derivative using Blach-Scholes model
    
    Parameters:
    - S: float - price of a underlying asset
    - K: float - strike price
    - r: float - risk-free rate
    - sigma: float - underlying asset volatility
    - Tau: float - time of the asset maturity
    
    Return:
    - V: float -
    - N1: float - 
    - N1: float - 
    """
    # Calculation for d1 a and d2
    d1 = (np.log(S / K) + (r + 0.5 * sigma**2) * Tau) / (sigma * np.sqrt(Tau))
    d2 = d1 - sigma * np.sqrt(T)

    # Calculation for N1 and N2
    N1 = norm.cdf(d1)
    N2 = norm.cdf(d2)

    # v calculation
    V = S * N1 - K * np.exp(-r * Tau) * N2

    return V, N1, N2

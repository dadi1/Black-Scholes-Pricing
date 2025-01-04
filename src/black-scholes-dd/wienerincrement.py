import numpy as np

# Defining constants 

T = 1 # One year of pricing
N = 30 # Trading day with
dt = T / N 

def wiener_increment(r, sigma, S0):
    """
    Simulation following a Wiener Process of the derivative price
    
    Parameters:
    - r: float - free risk rate
    - sigma: float - underlying asset volatility
    - S0: float - initial price of underlying asset

    Return:
    - St: float - price of the underlying asset for all Time
    """

    TT = np.linspace(0, T, N + 1) # Vector for all discrete times

    # Rate for all times
    R = np.exp((r - (sigma**2) / 2) * TT)
    R1 = np.exp(r * T)

    # Generating random seed
    seed1 = np.random.Generator() # Each simulation will get a random seed for it's own simulation

    # Generating random numbers 
    np.random.seed(seed1)

    # Wiener Process
    dW = np.random.normal(0, sqrt(dt), N) # Wiener increment
    W = np.cumsum(np.insert(dW, 0, 0)) # Cumulative Wiener Process

    # Price of the underlying asset for all discrete times
    St = S0 * R * np.exp(sigma * W)

    return St
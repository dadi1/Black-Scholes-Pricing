from blackscholes import *
from wienerincrement import *

# Test for black_scholes() module

S = 100  # Preço do ativo subjacente
K = 100  # Preço de exercício
T = 1    # Tempo até a maturidade (em anos)
r = 0.05 # Taxa livre de risco (5%)
sigma = 0.2 # Volatilidade anual (20%)

V, N1, N2 = black_scholes(S, K, T, r, sigma)
#print(V)
#print(N1)
#print(N2)

# End of test for black_scholes() module

# Test for wiener_increment() module

St = wiener_increment(r, sigma, S)

print(St)

# End wiener_increment() module
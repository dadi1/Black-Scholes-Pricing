from .blackscholes import *

S = 100  # Preço do ativo subjacente
K = 100  # Preço de exercício
T = 1    # Tempo até a maturidade (em anos)
r = 0.05 # Taxa livre de risco (5%)
sigma = 0.2 # Volatilidade anual (20%)

call_price = black_scholes(S, K, T, r, sigma, option_type="call")
put_price = black_scholes(S, K, T, r, sigma, option_type="put")

print(f"Preço da Call: {call_price:.2f}")
print(f"Preço da Put: {put_price:.2f}")
import numpy as np
from scipy.stats import norm

def black_scholes(S, K, T, r, sigma, option_type="call"):
    """
    Calcula o preço de uma opção europeia usando o modelo de Black-Scholes.

    Parâmetros:
    - S: float - preço atual do ativo subjacente
    - K: float - preço de exercício (strike price)
    - T: float - tempo até a maturidade (em anos)
    - r: float - taxa livre de risco (em termos decimais)
    - sigma: float - volatilidade anual do ativo subjacente
    - option_type: str - "call" para opção de compra ou "put" para opção de venda

    Retorna:
    - float: preço da opção calculado
    """
    # Cálculo dos parâmetros d1 e d2
    d1 = (np.log(S / K) + (r + 0.5 * sigma**2) * T) / (sigma * np.sqrt(T))
    d2 = d1 - sigma * np.sqrt(T)

    # Preço da opção baseado no tipo
    if option_type == "call":
        price = S * norm.cdf(d1) - K * np.exp(-r * T) * norm.cdf(d2)
    elif option_type == "put":
        price = K * np.exp(-r * T) * norm.cdf(-d2) - S * norm.cdf(-d1)
    else:
        raise ValueError("Tipo de opção inválido. Use 'call' ou 'put'.")

    return price


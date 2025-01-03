
# Gerar o caminho de Wiener para o ativo
np.random.seed(1355)  # Fixar a semente para reprodutibilidade
dW = np.random.normal(0, 1, N)  # Incrementos aleatórios
W = np.concatenate(([0], np.cumsum(dW)))  # Processo de Wiener
R = np.exp((r - 0.5 * sig**2) * np.linspace(0, T, N + 1))  # Fator de crescimento
St = S0 * R * np.exp(sig * W)  # Simulação de preço do ativo
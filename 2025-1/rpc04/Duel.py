# Leer el número de cartas
n = int(input().strip())

# Leer las cartas de Alice
alice_cards = [int(input().strip()) for _ in range(n)]

# Calcular las cartas de Bob
all_cards = set(range(1, 2 * n + 1))
bob_cards = sorted(all_cards - set(alice_cards))

# Ordenamos las cartas de Alice
alice_cards.sort()

# Máximo número de puntos
max_points = 0
bob_index = 0
for alice_card in alice_cards:
    while bob_index < n and bob_cards[bob_index] <= alice_card:
        bob_index += 1
    if bob_index < n:
        max_points += 1
        print(f"Alice card {alice_card} beats Bob card {bob_cards[bob_index]}")
        bob_index += 1

# Mínimo número de puntos
min_points = 0
bob_index = 0
for alice_card in alice_cards:
    if bob_cards[bob_index] > alice_card:
        min_points += 1
        print(f"Bob card {bob_cards[bob_index]} beats Alice card {alice_card}")
        bob_index += 1

# Imprimimos el resultado en el formato correcto
print(f"{min_points} {max_points}")
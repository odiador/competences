def min_operations_to_form_necklace(test_cases):
    results = []

    for case in test_cases:
        n = case['n']  # número de cadenas
        chains = case['chains']  # lista de longitudes de cadenas
        
        # Ordenamos las cadenas por su longitud
        chains.sort()
        
        # Iniciamos la cantidad de operaciones necesarias
        operations = 0
        
        # La idea es seguir abriendo enlaces de la cadena más corta hasta que
        # quedemos con una sola cadena. 
        # Cada operación reduce el número total de cadenas en uno.
        
        # Mientras tengamos más de una cadena
        while n > 1:
            # Si abrimos un enlace de la cadena más corta
            operations += 1
            # Si la cadena más corta se consume completamente
            # reducimos el número de cadenas
            if chains[0] == 1:  # Si la cadena más corta tiene 1 enlace
                chains.pop(0)  # Elimina la cadena más corta
            else:
                chains[0] -= 1  # Abrimos un enlace
            
            # Actualizamos el número de cadenas
            n = len(chains)

            # Si queda un solo enlace en la cadena más corta y sigue habiendo más cadenas
            if n > 1 and chains[0] == 1:
                chains.pop(0)  # Elimina la cadena más corta que ahora es 1
        
        results.append(operations//2)

    return results

# Leer datos de entrada
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    chains = list(map(int, input().split()))
    test_cases.append({'n': n, 'chains': chains})

# Obtener resultados
results = min_operations_to_form_necklace(test_cases)

# Imprimir resultados
for result in results:
    print(result)

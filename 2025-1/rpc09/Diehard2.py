die1 = list(map(int, input().split()))
die2 = list(map(int, input().split()))
die3 = list(map(int, input().split()))

def compare(dieA, dieB):
    cnt = 0
    for a in dieB:
        for b in dieA:
            if a > b:
                cnt += 1
    return (36 - cnt)

def dados_iguales(dieA, dieB):
    return sorted(dieA) == sorted(dieB)

def menor_dado(dados, indices):
    # Retorna el índice (1-based) del dado menor entre los dados indicados
    subdados = [sorted(dados[i]) for i in indices]
    min_idx = indices[0]
    for idx, dado in zip(indices, subdados):
        if dado < sorted(dados[min_idx]):
            min_idx = idx
    return min_idx + 1

def empate(dieA, dieB, ganador):
    if not dados_iguales(dieA, dieB):
        print(ganador)
    else:
        if len(set(dieA)) == 1:
            print("No dice")
        else:
            print(ganador)

cnt12 = compare(die1, die2)
cnt13 = compare(die1, die3)
cnt23 = compare(die2, die3)

if cnt12 > 0 and cnt13 > 0:
    print(1)
elif cnt12 < 0 and cnt23 > 0:
    print(2)
elif cnt13 < 0 and cnt23 < 0:
    print(3)
else:
    if cnt12 == 0 and cnt13 > 0:
        empate(die1, die2, 1)
    elif cnt12 == 0 and cnt23 > 0:
        empate(die1, die2, 2)
    elif cnt13 == 0 and cnt12 > 0:
        empate(die1, die3, 1)
    elif cnt13 == 0 and cnt23 < 0:
        empate(die1, die3, 3)
    elif cnt23 == 0 and cnt12 < 0:
        empate(die2, die3, 2)
    elif cnt23 == 0 and cnt13 < 0:
        empate(die2, die3, 3)
    elif cnt12 == 0 and cnt13 == 0 and cnt23 == 0:
        # Empate múltiple: buscar el menor dado ganador
        dados = [die1, die2, die3]
        if dados_iguales(die1, die2) and dados_iguales(die2, die3):
            if len(set(die1)) == 1:
                print("No dice")
            else:
                print(1)
        else:
            # Buscar el menor dado entre los empatados
            indices = [0,1,2]
            print(menor_dado(dados, indices))
    else:
        print("No dice")
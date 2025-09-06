from collections import deque
import sys


def leer_enteros():
    return list(map(int, sys.stdin.readline().split()))


def max_deslizante_1d(arr, k):
    # devuelve lista de máximos en ventanas de tamaño k
    dq = deque()
    res = []
    for i, val in enumerate(arr):
        while dq and arr[dq[-1]] <= val:
            dq.pop()
        dq.append(i)
        if dq[0] <= i - k:
            dq.popleft()
        if i >= k - 1:
            res.append(arr[dq[0]])
    return res


def maximos_ventana_2d(matriz, filas, columnas, alto, ancho):
    # Primera fase: máximos horizontales (ventana ancho) para cada fila
    ancho_salida = columnas - ancho + 1
    alto_salida = filas - alto + 1
    if ancho_salida <= 0 or alto_salida <= 0:
        return []

    aux = [None] * filas  # cada elemento será una lista de longitud ancho_salida
    for i in range(filas):
        aux[i] = max_deslizante_1d(matriz[i], ancho)

    # Segunda fase: para cada columna de aux aplicamos max_deslizante_1d verticalmente
    resultado = [[0] * ancho_salida for _ in range(alto_salida)]
    for j in range(ancho_salida):
        # construir columna
        columna = [aux[i][j] for i in range(filas)]
        max_col = max_deslizante_1d(columna, alto)
        for i in range(alto_salida):
            resultado[i][j] = max_col[i]
    return resultado


def main():
    datos = leer_enteros()
    if not datos:
        return
    filas, columnas = datos
    matriz = [leer_enteros() for _ in range(filas)]
    alto, ancho = leer_enteros()

    # Elegimos orientación: si la ventana es más alta que ancha, es más eficiente transponer
    if alto > ancho:
        # transponer matriz y swaps de dimensiones y de ventanas
        matriz_T = [list(row) for row in zip(*matriz)]
        res_T = maximos_ventana_2d(matriz_T, columnas, filas, ancho, alto)
        # transponer resultado de vuelta
        if not res_T:
            return
        resultado = [list(row) for row in zip(*res_T)]
    else:
        resultado = maximos_ventana_2d(matriz, filas, columnas, alto, ancho)

    # imprimir resultado
    for fila in resultado:
        print(' '.join(map(str, fila)))


if __name__ == '__main__':
    main()
def roman_to_int(s: str) -> int:
    # Mapa de valores romanos
    val = {'I':1, 'V':5, 'X':10, 'L':50,
           'C':100, 'D':500, 'M':1000}
    total = 0
    max_suf = 0
    # Recorremos de derecha a izquierda
    for c in reversed(s):
        v = val[c]
        if v < max_suf:
            total -= v
        else:
            total += v
            max_suf = v
    return total


import sys
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    romano = input().strip()
    print(roman_to_int(romano))

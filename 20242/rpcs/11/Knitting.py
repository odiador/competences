def main():
    import sys
    N, P = map(int, sys.stdin.readline().split())
    # Hueco tras patrón central + pares simétricos:
    L = (N - P) % (2 * P)
    # Si P es par y L>=P, colocamos uno más (queda L-P), si no, queda L.
    if P % 2 == 0 and L >= P:
        print(L - P)
    else:
        print(L)

if __name__ == "__main__":
    main()

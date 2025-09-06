MOD = 10**9 + 7

def main():
    import sys
    input = sys.stdin.readline

    s = input().strip()

    # Convertir el string a número módulo MOD
    yet = 0
    for c in s:
        yet = (yet * 10 + int(c)) % MOD

    here = 1
    i = 1
    while True:
        here = (here * i) % MOD
        if here == yet:
            print(i)
            return
        i += 1

if __name__ == "__main__":
    main()

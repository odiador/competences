
x = int(input())
for _ in range(x):
    p, r, y = map(float, input().split())
    each = y/4
    e = p/2+each
    w = -p/2+each
    n = r/2+each
    s = -r/2+each
    print(f"{n} {e} {s} {w}")

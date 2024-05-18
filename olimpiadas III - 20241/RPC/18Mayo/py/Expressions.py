import re

n, m = map(int, input().split())
p = re.findall(r'\d+|[+\-*]', input())

print("even" if eval("".join(p)) % 2 == 0 else "odd")

for i in range(m):
    x, y = input().split()
    p[(int(x) - 1) * 2] = y
    print("even" if eval("".join(p)) % 2 == 0 else "odd")

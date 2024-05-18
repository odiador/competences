c = int(input())
s = input()
n = ""

for i in range(c - 1):
    n += s[i]
    if s[i] == '(' and s[i + 1] == ')':
        n += "1"
    elif s[i] == ')' and s[i + 1] == '(':
        n += "*"
    elif s[i] == ')' and s[i + 1] == ')':
        n += "+1"

n += s[c - 1]
print(eval(n))

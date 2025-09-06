n,k = map(int, input().split())
# n cantidad legos
# k espacios


def x(pos,num):
    if num == 1:
        return 1
    if pos == 0:
        return x(pos+1,num-1)
    if pos == k-1:
        return x(pos-1,num-1)
    return x(pos-1,num-1) + x(pos+1,num-1)

cant = 0
for i in range(0,k//2):
    cant += x(i, n)
cant*=2
if k%2==1:
    cant += x(k//2, n)
print(cant % int(1e9+7))
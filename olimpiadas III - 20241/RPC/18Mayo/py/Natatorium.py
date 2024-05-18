

c = int(input())
m = int(input())
p = list(map(int, input().split()))

arr = []
for n in p:
    if c % n == 0 and len(arr) < 2:
        arr.append(n)
print(f"{arr[0]} {arr[1]}" if arr[0] < arr[1] else f"{arr[1]} {arr[0]}")

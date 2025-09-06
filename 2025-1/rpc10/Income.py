m = int(input())
arr = list(map(int, input().split()))

sum = sum(arr)
for i in range(m):
    arr[i] = arr[i]*100/sum

arr.sort()

part = 100/m

result = 0
for x in arr:
    if x > part:
        result+=x-part
result = result if result !=0 else arr[0]-part

print(f"{result:.6f}")

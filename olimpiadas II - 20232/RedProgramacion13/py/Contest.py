from itertools import combinations

def is_nice(arr):
    if len(arr) < 3:
        return True
    for i in range(2, len(arr)):
        if arr[i] > arr[i - 1] + arr[i - 2]:
            return False
    return True

n, k = map(int, input().split())
nums = [list(map(int, input().split())) for _ in range(n)]

count = 0
for comb in combinations(nums, k):
    if is_nice([y for x in comb for y in x]):
        count += 1

print(count)

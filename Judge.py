judges, days = map(int, input().split())
cnt = [judges]*days
for _ in range(judges):
    each = list(map(int,input().split()))
    for i in range(1, len(each)-1,2):
        # arr[x:y+1] = [val + 1 for val in arr[x:y+1]]
        cnt[each[i]-1:each[i+1]] = [val - 1 for val in cnt[each[i]-1:each[i+1]]]
c =0
for x in cnt:
    if x>=3:
        c+=1
print(c)
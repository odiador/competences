n, m = map(int, input().split())
ls = [[0]*m]*n
for j in range(n):
    s = input()
    a = [0]*m
    for i in range(m):
        if s[i] == "1":
            a[i] = 1
    ls[j] = a


consecutive = [0]*m
maxValue = 0
for i in range (n):
    for j in range (m):
        if ls[i][j]== 0:
            consecutive[j] = 0
        else:
            consecutive[j]+=1
    maxConsecutive = max(consecutive)
    maxValue = max(maxConsecutive, maxValue)
    
    while maxConsecutive > 0:
        cnt = 0
        for cons in consecutive:
            if cons >= maxConsecutive:
                cnt+=1
        maxValue = max(maxValue, cnt*maxConsecutive)
        maxConsecutive-=1
print(maxValue)
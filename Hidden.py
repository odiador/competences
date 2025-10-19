f1 =input()
f2 =input()
f3 =input()

mp = {"1":0,"2":0,"3":0}
i = 0
j = 0
k = 0
n1 = len(f1)
n2 = len(f2)
n3 = len(f3)
res = ""
while(i<n1 and j<n2) or (i<n1 and k<n3) or (j<n2 and k<n3):
    if i<n1:
        mp[f1[i]]+=1
    if j<n2:
        mp[f2[j]]+=1
    if k<n3:
        mp[f3[k]]+=1
    for key,v in mp.items():
        if(v==2):
            if i<n1 and f1[i]==key:
                i+=1
            if j<n2 and f2[j]==key:
                j+=1
            if k<n3 and f3[k]==key:
                k+=1
            res+=key
    mp = {"1":0,"2":0,"3":0}
print(res)
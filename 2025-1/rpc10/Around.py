l,r = map(int, input().split())
cant = l+r
rnormal = True
lmoving = l
rmoving = l+1
lnormal = True
reboot = cant*2


x = set()
i = 0

while reboot>0:
    x.add((lmoving,rmoving))
    x.add((rmoving,lmoving))
    if i %2== 0 and lnormal:
        lmoving-=1
        if lmoving ==0:
            lnormal = False
            lmoving = l+1
    elif i %2== 0:
        lmoving+=1
        if lmoving==cant+1:
            lmoving=l
            
    if i %2== 1 and rnormal:
        rmoving+=1
        if rmoving ==cant+1:
            rnormal = False
            rmoving = l
    elif i %2== 1:
        rmoving-=1
        if rmoving==0:
            rmoving=l+1
    reboot-=1
    i+=1
print(len(x)//2)
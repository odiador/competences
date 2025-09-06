from math import pi
# Kettle Kitten
# 3 19 quantity of kettles | volume of kitten
# 2 3 height and rad of each kettle
# 4 2
# 6 1

n,vol = map(int, input().split())
vol = vol/pi

min = float('inf')
bidx = -1

for i in range(n):
    h,r = map(int, input().split())
    evol =  r * r * h
    if evol < min and evol >= vol:
        min = evol
        bidx = i+1
print(bidx if bidx != -1 else "impossible")
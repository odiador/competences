g, r = map(int, input().split())

mix = min(g, r)
g -= mix

total_boost = mix * 10

total_boost += (g // 3) * 10
rem = g % 3

if rem == 2:
    total_boost += 3  
elif rem == 1:
    total_boost += 1  
print(total_boost)

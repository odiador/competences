def pretty(num, decimals=13):
    s = f"{num:.{decimals}f}"  # format with fixed decimals
    s = s.rstrip('0').rstrip('.')  # remove trailing zeros and dot
    return s

days = int(input())
initVolOH, initVolNorm = map(int, input().split())
deltaOH,deltaNorm = map(int, input().split())

endVolOH = initVolOH-deltaOH*days
endVolNorm = initVolNorm-deltaNorm*days
endVolOH = max(0,endVolOH)
endVolNorm =max(0,endVolNorm)
comp = endVolNorm+endVolOH
res = 0
if endVolOH%comp==0:
    res = endVolOH*100//comp
else:
    res = endVolOH*100/comp

print(pretty(res,13))
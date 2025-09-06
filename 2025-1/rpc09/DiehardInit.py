die1 = list(map(int, input().split()))
die2 = list(map(int, input().split()))
die3 = list(map(int, input().split()))

def compare(dieA, dieB):
    cnt = 0
    for a in dieA:
        for b in dieB:
            if a > b:
                cnt += 1
            elif a < b:
                cnt -= 1
    return cnt

cnt12 = compare(die1, die2)
cnt13 = compare(die1, die3)
cnt23 = compare(die2, die3)

if cnt12 > 0 and cnt13 > 0:
    print(1)
elif cnt12 < 0 and cnt23 > 0:
    print(2)
elif cnt13 < 0 and cnt23 < 0:
    print(3)
elif cnt12 == 0 and cnt13 == 0 and cnt23 == 0:
    print(1)
else:
    print("No dice")
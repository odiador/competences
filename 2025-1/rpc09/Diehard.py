
die1 = list(map(int, input().split()))
die2 = list(map(int, input().split()))
die3 = list(map(int, input().split()))

def win_prob(dieA, dieB):
    wins = losses = 0
    for a in dieA:
        for b in dieB:
            if a > b:
                wins += 1
            elif a < b:
                losses += 1
    if wins + losses == 0:
        return 0.0
    return wins / (wins + losses)

p12 = win_prob(die1, die2)
p21 = win_prob(die2, die1)
p13 = win_prob(die1, die3)
p31 = win_prob(die3, die1)
p23 = win_prob(die2, die3)
p32 = win_prob(die3, die2)

if min(p12, p13) >= 0.5:
    print(1)
elif min(p21, p23) >= 0.5:
    print(2)
elif min(p31, p32) >= 0.5:
    print(3)
else:
    print("No dice")
r, c = map(int, input().split())
for i in range(1, r + 1):
    w = input().strip()
    blanks = c - len(w)
    left = blanks // 2
    right = blanks - left
    # If blanks odd and row is even (2nd,4th,...), swap to have left > right
    if blanks % 2 == 1 and i % 2 == 0:
        left, right = right, left
    print('.' * left + w + '.' * right)

def main():
    x = input()
    mp = {}
    for ch in x:
        if ch in mp:
            mp[ch] += 1
        else:
            mp[ch] = 1
    foundOdd = False
    for key, value in mp.items():
        if value % 2 == 1:
            if foundOdd:
                print("no")
                return
            foundOdd = True
    print("yes")
main()
m = int(input())
dict = set()
for _ in range(m):
    s = input()
    dict.add(s)


m = int(input())

for _ in range(m):
    word = input()
    found = False
    if word in dict:
        print("1")
        found = True
        continue
    for dictword in dict:
        if word.startswith(dictword):
            # found fst
            searching = word[len(dictword):] 
            for secondword in dict:
                if secondword == searching:
                    print("2")
                    found = True
                    break
            if found:
                break
    if not found:
        print("0")
        continue

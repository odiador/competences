while True:
    infoString = input();
    info = infoString.split(" ")
    people = int(info[0])
    stock = int(info[1])
    counter = 0
    actions = [False] * 8

    for i in range(people):
        info = input().split()
        x = int(info[0])
        y = int(info[1])

        if not actions[0] and x == 0 and y > 0:
            actions[0] = True
        elif not actions[1] and x > 0 and x == y:
            actions[1] = True
        elif not actions[2] and x > 0 and y == 0:
            actions[2] = True
        elif not actions[3] and x > 0 and y == -x:
            actions[3] = True
        elif not actions[4] and x == 0 and y < 0:
            actions[4] = True
        elif not actions[5] and x < 0 and y == x:
            actions[5] = True
        elif not actions[6] and x < 0 and y == 0:
            actions[6] = True
        elif not actions[7] and x < 0 and y == -x:
            actions[7] = True
        else:
            continue

        counter++;

    print("WAIT" if counter > stock else "ATTACK")
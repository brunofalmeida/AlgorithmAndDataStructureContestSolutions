def is_dangerous (well, position):
    if well [position [0]] [position [1]] == True:
        return True
    else:
        return False

well = {}
for x in range (-201, 200):
    column = {}
    for y in range (-200, 0):
        column [y] = False
    well [x] = column

well [-1] [-5] = well [-1] [-6] = well [-1] [-7] = True
well [0] [-1] = well [0] [-2] = well [0] [-3] = well [0] [-7] = True
well [1] [-3] = well [1] [-7] = True
well [2] [-3] = well [2] [-7] = True
well [3] [-3] = well [3] [-4] = well [3] [-5] = well [3] [-7] = True
well [4] [-5] = well [4] [-7] = True
well [5] [-3] = well [5] [-4] = well [5] [-5] = well [5] [-7] = True
well [6] [-3] = well [6] [-7] = True
well [7] [-3] = well [7] [-4] = well [7] [-5] = well [7] [-6] = well [7] [-7] = True

position = [-1, -5]

while True:
    command = raw_input ().strip ().split ()
    if command [0] == "q":
        break
    
    danger = False
    
    for x in range (int (command [1])):
        if command [0] == "l":
            position [0] -= 1
        elif command [0] == "r":
            position [0] += 1
        elif command [0] == "d":
            position [1] -= 1
        elif command [0] == "u":
            position [1] += 1
            
        if is_dangerous (well, position):
            danger = True

        well [position [0]] [position [1]] = True

    print position [0], position [1],
    if danger:
        print "DANGER"
        break
    else:
        print "safe"

nums = {"A": 0, "B": 0}

while True:
    inp = raw_input ().strip ().split ()
    
    if inp [0] == "1":
        nums [inp [1]] = int (inp [2])

    elif inp [0] == "2":
        print nums [inp [1]]

    elif inp [0] == "3":
        nums [inp [1]] += nums [inp [2]]

    elif inp [0] == "4":
        nums [inp [1]] *= nums [inp [2]]

    elif inp [0] == "5":
        nums [inp [1]] -= nums [inp [2]]

    elif inp [0] == "6":
        nums [inp [1]] /= nums [inp [2]]

    elif inp [0] == "7":
        break

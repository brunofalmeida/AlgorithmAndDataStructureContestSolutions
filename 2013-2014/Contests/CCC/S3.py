T = int (raw_input ())

for i in range (T):
    N = int (raw_input ())

    # Create stacks
    top = []
    for j in range (N):
        top.append (int (raw_input () ) )
    branch = []
    lake = []
    
    needed = 1
    ans = "Y"

    while True:
        if len (top) > 0 and top [-1] == needed:
            lake.append (top.pop () )
            needed += 1
            if needed > N:
                break
            
        elif len (branch) > 0 and branch [-1] == needed:
            lake.append (branch.pop () )
            needed += 1
            if needed > N:
                break
            
        elif len (top) > 0:
            branch.append (top.pop () )

        else:
            ans = "N"
            break

    print ans

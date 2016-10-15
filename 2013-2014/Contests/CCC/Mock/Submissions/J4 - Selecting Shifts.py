def convert_time (time):
    ''' hh:mmXM to m '''
    if time [5:] == "AM":
        m = int (time [0:2]) * 60
    else:
        m = (int (time [0:2]) + 12) * 60
        
    m += int (time [3:5])
    
    return m

def bobTime (bob, alice):
    if bob [0] <= alice [0]:         # Bob starts before Alice
        if bob [1] <= alice [0]:     # Bob ends before Alice starts
            return 0
        elif bob [1] <= alice [1]:     # Bob ends before Alice ends
            return bob [1] - alice [0]
        else:                        # Bob ends after Alice ends
            return alice [1] - alice [0]
        
    else:                            # Alice starts before Bob
        if alice [1] <= bob [0]:     # Alice ends before Bob starts
            return 0
        elif alice [1] <= bob [1]:   # Alice ends before Bob ends
            return alice [1] - bob [0]
        else:                       # Alice ends after Bob ends
            return bob [1] - bob [0]

[T1, T2] = raw_input ().strip ().split ()
bob = (convert_time (T1), convert_time (T2) )

N = int (raw_input ())

shifts_original = []
shifts = []
for i in range (N):
    inp = raw_input ().strip ().split ()
    shifts_original.append ( (inp [0], inp [1] ) )
    shifts.append ( (convert_time (inp [0]), convert_time (inp [1]) ) )

shifts_times = []
for i in range (N):
    shifts_times.append (bobTime (bob, shifts [i]) )

max_time = max (shifts_times)
if max_time == 0:
    print "Call in a sick day."
else:
    for i in range (N):
        if shifts_times [i] == max_time:
            print shifts_original [i] [0], shifts_original [i] [1]
            break

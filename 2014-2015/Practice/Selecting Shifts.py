def convert_time(time):
    "hh:mmXM to m"
    if time[5:7] == "AM":
        if int(time[0:2]) < 12:
            m = int(time[0:2]) * 60
        else:
            m = 0
            
    else:
        if int(time[0:2]) < 12:
            m = ( int(time[0:2]) + 12 ) * 60
        else:
            m = 12 * 60
        
    m += int(time [3:5])
    
    return m


[T1, T2] = raw_input().strip().split()
bob = ( convert_time(T1), convert_time(T2) )

N = int(raw_input())

shifts_original = []
shifts = []
for i in range(N):
    inp = raw_input().strip().split()
    shifts_original.append( ( inp[0], inp[1] ) )
    shifts.append ( ( convert_time(inp[0]), convert_time(inp[1]) ) )

shifts_times = []
for i in range(N):
    shifts_times.append( min( bob[1], shifts[i][1] ) - max( bob[0], shifts[i][0] ) )

max_time = max(shifts_times)
if max_time <= 0:
    print "Call in a sick day."
else:
    for i in range(N):
        if shifts_times[i] == max_time:
            print shifts_original[i][0], shifts_original[i][1]
            break

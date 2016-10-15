from math import ceil

P = int(raw_input())
Q = int(raw_input())
W = int(raw_input())

Pd = P / 100.0
Qd = Q / 100.0
Wd = W / 100.0

if (P * (1 - Wd)) + W >= Q - 0.5:
    marksEarned = P * (1 - Wd)
    marksNeeded = Q - marksEarned - 0.5
    
    examPercentNeeded = int(ceil(marksNeeded / W * 100.0))
        
    if examPercentNeeded >= 0:
        print examPercentNeeded
    else:
        print 0
else:
    print "DROP THE COURSE"

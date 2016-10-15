# input
D, H, M = map(int, raw_input().strip().split()) # end time


# algorithm
minutes = ( (D - 11) * 24 * 60 ) + ( (H - 11) * 60 ) + ( M - 11 )


# output
if (D == 11 and H < 11) or (D == 11 and H == 11 and M < 11):    # end before start
    print -1
else:
    print minutes

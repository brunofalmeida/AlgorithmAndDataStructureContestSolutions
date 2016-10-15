x, y = map( int, raw_input().strip().split() )

x1, y1, x2, y2 = map( int, raw_input().strip().split() )

if (x1 <= x <= x2 or x2 <= x <= x1) and (y1 <= y <= y2 or y2 <= y <= y1):
    print "Yes"
else:
    print "No"

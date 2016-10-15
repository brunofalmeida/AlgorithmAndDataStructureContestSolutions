A = int (raw_input ())
B = int (raw_input ())
C = int (raw_input ())

if A + B + C == 180:
    if A == B == C:
        print "Equilateral"
    elif A == B or A == C or B == C:
        print "Isosceles"
    else:
        print "Scalene"
        
else:
    print "Error"

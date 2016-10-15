number = input ()

for x in range (number):
    grade = input ()

    if grade >=0 and grade <= 100:
        if grade < 50:
            print "F"
        elif grade < 60:
            print "D"
        elif grade < 70:
            print "C"
        elif grade < 80:
            print "B"
        elif grade <= 100:
            print "A"
    else:
        print "X"

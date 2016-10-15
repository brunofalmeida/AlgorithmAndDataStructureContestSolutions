a = int(raw_input())
b = int(raw_input())
c = int(raw_input())

if a + b > c and b + c > a and a + c > b:
    print "Huh? A triangle?"
else:
    print "Maybe I should go out to sea..."

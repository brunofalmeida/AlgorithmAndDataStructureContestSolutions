word = raw_input ()

is_possible = True
for x in word:
    if not x in "IOSHZXN":
        is_possible = False
        break

if is_possible:
    print "YES"
else:
    print "NO"

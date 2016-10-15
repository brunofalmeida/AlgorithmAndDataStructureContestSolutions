# http://wcipeg.com/problem/ccc13j2


word = raw_input()

isPossible = True
for letter in word:
    if letter not in "IOSHZXN":
        isPossible = False
        break

if isPossible:
    print "YES"
else:
    print "NO"

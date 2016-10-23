one = raw_input()
two = raw_input()

anagram = True

for i in range(ord('a'), ord('z') + 1):
    char = chr(i)

    if (two.count(char) > one.count(char)):
        anagram = False

if anagram:
    print "A"
else:
    print "N"

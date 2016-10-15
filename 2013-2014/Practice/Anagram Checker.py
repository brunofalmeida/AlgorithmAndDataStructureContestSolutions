phrase1 = list (raw_input ().strip ())
phrase2 = list (raw_input ().strip ())

while True:
    try:
        phrase1.remove (" ")
    except:
        break

while True:
    try:
        phrase2.remove (" ")
    except:
        break

phrase1.sort ()
phrase2.sort ()

if phrase1 == phrase2:
    print "Is an anagram."
else:
    print "Is not an anagram."

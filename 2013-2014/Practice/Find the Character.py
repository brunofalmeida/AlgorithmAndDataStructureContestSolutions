letter = raw_input ().lower ()
phrase = raw_input ()
counter = 0

for x in phrase.lower ():
    if x == letter:
        counter += 1

print phrase
print counter

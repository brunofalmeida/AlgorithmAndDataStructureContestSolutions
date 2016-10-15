phrase1 = raw_input()
phrase2 = raw_input()

# remove spaces from both phrases
phrase1 = phrase1.replace(" ", "")
phrase2 = phrase2.replace(" ", "")

# convert both phrases to lists of characters
phrase1 = list(phrase1)
phrase2 = list(phrase2)

# sort both phrases according to characters
phrase1.sort()
phrase2.sort()

if phrase1 == phrase2:
    print "Is an anagram."
else:
    print "Is not an anagram."

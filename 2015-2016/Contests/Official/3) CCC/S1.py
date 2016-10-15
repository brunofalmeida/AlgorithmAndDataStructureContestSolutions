first = raw_input()
second = raw_input()

# Start by assuming it is an anagram
anagram = True


# Loop through all characters from 'a' to 'z'
# In Python, ord() converts from a character to the the ASCII number,
# and  chr() converts an ASCII number to the character
# (Type help(ord) or help(chr) into the Python Shell for more information)
for i in range(ord('a'), ord('z') + 1):
    char = chr(i)

    # If char occurs more in the second word than the first, it is not an anagram
    # (The first word might have more occurrences than the second,
    #  but not the other way around because asterisks only occur in the second word)
    if (second.count(char) > first.count(char)):
        anagram = False


if anagram:
    print "A"
else:
    print "N"

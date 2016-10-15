# Input the two digit code as a string
code = raw_input()


# Go through an if/elif/else chain to print the appropriate message
# Only one of the following bodies (indented code blocks) will execute

# The first True condition will run its body and print the appropriate message,
# then skip the rest of the conditions
# If none of the conditions are True, the body of the else block will run
# and print "invalid code"

# Spelling and capitalization counts!

if code == "MG":
    print "midget girls"
elif code == "MB":
    print "midget boys"
elif code == "JG":
    print "junior girls"
elif code == "JB":
    print "junior boys"
elif code == "SG":
    print "senior girls"
elif code == "SB":
    print "senior boys"
else:
    print "invalid code"

parts = raw_input()

missing = ""
for letter in "BFTLC":
    if letter not in parts:
        missing += letter

if len(missing):
    print missing
else:
    print "NO MISSING PARTS"

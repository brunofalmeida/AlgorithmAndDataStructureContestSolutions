N = int (raw_input ())
rope = []
for i in range (N):
    rope.append (raw_input ())

string = ""
for i in range (1, len (rope) + 1):
    if -i % 2 == 1:
        string += rope [-i].strip ()
    else:
        string += rope [-i].strip () [::-1]

print string

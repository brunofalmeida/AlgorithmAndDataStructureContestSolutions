N = int (raw_input ())
first = raw_input ().split ()
second = raw_input ().split ()

pairs = {}
for i in range (N):
    pairs [first [i] ] = second [i]

answer = "good"

for one in pairs:
    two = pairs [one]
    if one == two:
        answer = "bad"
        break

    elif pairs [two] != one:
        answer = "bad"
        break

print answer

N = int (raw_input ())
first = raw_input ().split ()
second = raw_input ().split ()

answer = "good"

for i1 in range (N):
    if first [i1] == second [i1]:
        answer = "bad"
        break

    else:
        i2 = first.index (second [i1] )
        if second [i2] != first [i1]:
            answer = "bad"
            break

print answer

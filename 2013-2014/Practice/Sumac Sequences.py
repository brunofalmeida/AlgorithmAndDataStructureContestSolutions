sequence = [int (raw_input ())]
sequence.append (int (raw_input ()))

x = 2
while True:
    sequence.append (sequence [x - 2] - sequence [x - 1])
    if sequence [x] > sequence [x - 1]:
        break
    x += 1

print len (sequence)

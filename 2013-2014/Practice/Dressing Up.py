H = int (raw_input ())

for i in range (1, H + 1, 2):
    print ("*" * i) + (" " * (2 * (H - i) ) ) + ("*" * i)

for i in range (H - 2, 0, -2):
    print ("*" * i) + (" " * (2 * (H - i) ) ) + ("*" * i)

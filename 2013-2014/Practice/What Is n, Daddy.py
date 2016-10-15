n = int (raw_input ())
counter = 0

for a in range (1, n + 1):
    b = n - a
    if a >= b and 0 <= a <= 5 and 0 <= b <= 5:
        counter += 1

print counter

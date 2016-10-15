n = int (raw_input ())
ops = 0

while n != 1:
    n = n / 2.0 + (5.0 / 2 * n + 1) * (n % 2)
    ops += 1

print ops

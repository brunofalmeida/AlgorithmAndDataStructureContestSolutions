p = float (raw_input ()) / 100.0
y = int (raw_input ())
n = int (raw_input ())
end = int (raw_input ())

for x in range (end - y):
    n += p * n

print int (round (n, 0))

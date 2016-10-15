n = int (raw_input ())

graph = [ [] for i in xrange (n + 1) ]

while True:
    x, y = map (int, raw_input ().strip ().split () )
    if (x, y) == (0, 0):
        break
    graph [x].append (y)

opt = [0 for i in xrange (n + 1) ]
opt [n] = 1

for a in range (n - 1, 0, -1):
    for b in graph [a]:
        opt [a] += opt [b]

print opt [1]

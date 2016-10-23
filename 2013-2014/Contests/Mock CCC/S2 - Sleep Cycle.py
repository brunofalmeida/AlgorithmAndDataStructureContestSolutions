DEBUG = True

N = int (raw_input ())
hypnogram = map (int, raw_input ().strip ().split () )


minimum = min (hypnogram)
min_indexes = []

for i in range (N):
    if hypnogram [i] == minimum:
        min_indexes.append (i)

if DEBUG:
    print "Minimum indexes:", min_indexes


dips = []

for m in min_indexes:
    if len (dips) >= 1:
        if dips [-1] [0] <= m <= dips [-1] [1]:
            continue
        
    dips.append ( [m, m] )
    
    i = m - 1
    while i >= 0:
        if hypnogram [i] > hypnogram [i + 1]:
            dips [-1] [0] -= 1
        else:
            break
        i -= 1

    i = m + 1
    while i <= N - 1:
        if hypnogram [i] > hypnogram [i - 1]:
            dips [-1] [0] += 1
        else:
            break
        i += 1


delete = []

for i, d in enumerate (dips):
    if d [1] - d [0] + 1 < 3:
        delete.append (i)

    elif d [0] == d [1] or d [-2] == d [-1]:
        delete.append (i)
        
for i in delete [::-1]:
    del dips [i]


maximum = 0
for d in dips:
    if d [1] - d [0] + 1 > maximum:
        maximum = d [1] - d [0] + 1

print maximum

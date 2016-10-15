start, days = map (int, raw_input ().strip ().split () )

print "Sun Mon Tue Wed Thr Fri Sat"

for i in range (start - 1):
    print "   ",

for i in range (days):
    print str (i + 1).rjust (3),
    if i % 7 == (7 - start) or i == days:
        print

n = int (raw_input ())

a_pts = d_pts = 100

for i in range (n):
    [a, d] = map (int, raw_input ().split () )

    if a > d:
        d_pts -= a
    elif d > a:
        a_pts -= d

print a_pts
print d_pts

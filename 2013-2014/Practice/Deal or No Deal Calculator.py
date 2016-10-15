cases = {}
cases [1] = 100
cases [2] = 500
cases [3] = 1000
cases [4] = 5000
cases [5] = 10000
cases [6] = 25000
cases [7] = 50000
cases [8] = 100000
cases [9] = 500000
cases [10] = 1000000

n = int (raw_input ())
left = 10
total = sum (cases.values ())
for i in range (n):
    total -= cases [int (raw_input ())]
    left -= 1

offer = int (raw_input ())

if offer > float (total) / left:
    print "deal"
else:
    print "no deal"

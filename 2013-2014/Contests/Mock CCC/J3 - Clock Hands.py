H = float (raw_input ())
M = float (raw_input ())
S = float (raw_input ())

h = H
m = h + M
while m >= 360:
    m -= 360 
s = m + S
while s >= 360:
    s -= 360

hours = int (h / 30)
if hours == 0:
    hours = 12
minutes = int (m / 6)
seconds = int (round (s / 6.0, 0) )

strings = [str (hours), str (minutes), str (seconds) ]
for i in range (3):
    if len (strings [i]) == 1:
        strings [i] = "0" + strings [i]

print strings [0] + ":" + strings [1] + ":" + strings [2]

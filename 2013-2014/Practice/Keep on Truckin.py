points = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]

A = int (raw_input ())
B = int (raw_input ())
for i in range (int (raw_input ()) ):
    points.append (int (raw_input ()))
points.sort ()

motels = []
for p in points:
    motels.append ( [p, 0] )
motels [-1] [1] = 1

for i in range (len (motels) - 2, -1, -1):
    for m in motels [i + 1:]:
        if A <= m [0] - motels [i] [0] <= B:
            motels [i] [1] += m [1]                 

print motels [0] [1]

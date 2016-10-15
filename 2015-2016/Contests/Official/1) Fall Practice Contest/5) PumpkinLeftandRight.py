N = int(raw_input())
T = int(raw_input())

left = []
right = []

for i in xrange(N):
    coor = int(raw_input())
    
    if coor < 0:
        left.append(coor)
    if coor > 0:
        right.append(coor)
        
left.sort()
right.sort()
left = left[::-1]
ans = 1e9

for i in range(1, min(len(left), T) + 1):
    j = T - i
    if (j > len(right)):
        continue
    
    ans = min(ans, abs(left[i - 1]) + abs(right[j - 1] - left[i - 1]))

for i in range(1, min(len(right), T) + 1):
    j = T - i
    if (j > len(left) or j == 0):
        continue
    
    ans = min(ans, abs(right[i - 1]) + abs(left[j - 1] - right[i - 1]))

if len(left) >= T:
    ans = min(ans, abs(left[T - 1]))
if len(right) >= T:
    ans = min(ans, abs(right[T - 1]))

print ans

def f(l, r, p):
    if l + r == T:
        return 0
    if dp[l][r][p] != -1:
        return dp[l][r][p]
    
    ans = 1e9
    
    if (l < len(left) - 1):
        if (p == 0):
            ans = min(ans, f(l + 1, r, 0) + abs(left[l + 1] - left[l]))
        else:
            ans = min(ans, f(l + 1, r, 0) + abs(left[l + 1] - right[r]))
            
    if (r < len(right) - 1):
        if (p == 0):
            ans = min(ans, f(l, r + 1, 1) + abs(right[r + 1] - left[l]))
        else:
            ans = min(ans, f(l, r + 1, 1) + abs(right[r + 1] - right[r]))
            
    dp[l][r][p] = ans
    return dp[l][r][p]


N = int(raw_input())
T = int(raw_input())

left = [0]
right = [0]

for i in xrange(N):
    coor = int(raw_input())
    if coor < 0:
        left.append(coor)
    if coor > 0:
        right.append(coor)
        
left.sort()
right.sort()
left = left[::-1]

dp = [[[-1 for i in range(2)] for j in range(len(right) + 1)] for i in range(len(left) + 1)]

print f(0, 0, 0)

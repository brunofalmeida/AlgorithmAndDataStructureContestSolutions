N, K = map( int, raw_input().strip().split() )

total = 0

for i in range(N):
    a, b = map( int, raw_input().strip().split() )
    total += a * b

print total % K

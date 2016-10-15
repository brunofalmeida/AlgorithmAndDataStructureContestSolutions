N = int(raw_input())
for i in range(N):
    A, B, P = map(int, raw_input().strip().split())

    if A * B != P:
        print "16 BIT S/W ONLY"
    else:
        print "POSSIBLE DOUBLE SIGMA"

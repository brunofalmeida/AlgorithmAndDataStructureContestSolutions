C, F, S = map(int, raw_input().strip().split()) # calories, fat, sodium limit
N = int(raw_input())    # number of items on menu

for i in range(N):
    inp = raw_input().strip().split()
    Xi = float(inp[0])
    Ci = float(inp[1])
    Fi = float(inp[2])
    Si = float(inp[3])

    if Ci/Xi <= C and Fi/Xi <= F and Si/Xi <= S:
        print " ".join(inp[4:])

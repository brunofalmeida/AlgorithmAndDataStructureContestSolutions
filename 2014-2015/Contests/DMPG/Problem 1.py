C = int(raw_input())
R, W, B, Y, G = map(int, raw_input().strip().split())

if R % 4 == 0:
    r = R / 4
else:
    r = R / 4 + 1

if W % 5 == 0:
    w = W / 5
else:
    w = W / 5 + 1

if B % 4 == 0:
    b = B / 4
else:
    b = B / 4 + 1

if Y % 3 == 0:
    y = Y / 3
else:
    y = Y / 3 + 1

if G % 6 == 0:
    g = G / 6
else:
    g = G / 6 + 1

print max(0, C - (r + w + b + y + g))

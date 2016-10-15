N = int(raw_input())
ren = int(raw_input())
ans = "YES"

for i in range(N - 1):
    num = int(raw_input())
    if num >= ren:
        ans = "NO"
        break

print ans

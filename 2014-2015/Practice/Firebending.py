n = int(raw_input())
sum = 0

for i in range(n):
    num = int(raw_input())
    if num >= 0:
        sum += num
    else:
        sum -= num

print sum

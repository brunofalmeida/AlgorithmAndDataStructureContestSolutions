line = raw_input()

count = 0

for num in range(1, 10):
    if line.find("00" + str(num)) != -1:
        count += 1

print count

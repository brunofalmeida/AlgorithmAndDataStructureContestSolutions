N = int(raw_input())
read = map(int, raw_input().strip().split())


lowIndex = 0
lowValue = read[0]
for i in range(1, len(read)):
    if read[i] < lowValue:
        lowIndex = i
        lowValue = read[i]

highIndex = 0
highValue = read[0]
for i in range(1, len(read)):
    if read[i] > highValue:
        highIndex = i
        highValue = read[i]


unknown = False
for i in range(lowIndex, highIndex):
    if read[i] >= read[i + 1]:
        unknown = True
        break


if unknown:
    print "unknown"
else:
    print highValue - lowValue

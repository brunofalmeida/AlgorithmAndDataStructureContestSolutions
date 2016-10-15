numbers = []
for x in range (0, 101):
    numbers.append (0)
    
while True:
    number = input ()
    if number == -1:
        break
    numbers [number] += 1

numbers_sorted = numbers [:]
numbers_sorted.sort ()
high = numbers_sorted [-1]

for x in range (len (numbers)):
    if numbers [x] == high:
        print x

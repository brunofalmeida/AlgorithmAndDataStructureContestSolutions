DEBUG = False

raw_input()
boys = map(int, raw_input().strip().split() )
[A, B] = map(int, raw_input().strip().split() )

name = 1
distance = 0

A += int(A % 2 == 0)    # make A odd
B -= int(B % 2 == 0)   # make B odd


if A < boys[0]:
    if boys[0] - A > distance:
        name = A
        distance = boys[0] - A
        

for i in range(len(boys) - 1):
    avg = ( boys[i] + boys[i + 1] ) / 2
    
    num = avg + int(avg % 2 == 0)     # make avg odd
       
    if A <= num <= B:
        if boys[i + 1] - num > distance:
            name = num
            distance = boys[i + 1] - num

    elif boys[i] < A < boys[i + 1]:
        if boys[i + 1] - A > distance:
            name = A
            distance = boys[i + 1] - A

    elif boys[i] < B < boys[i + 1]:
        if B - boys[i] > distance:
            name = B
            distance = B - boys[i]


if boys[-1] < B:
    if B - boys[-1] > distance:
        name = B
        distance = B - boys[-1]


print name

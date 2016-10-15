def is_reversable(a, b):
    if (a == "6" and b == "9") or (a == "9" and b == "6") or (a == b and a in "018"):
        return True
    return False

interval = map(int, raw_input().strip().split() )
if len(interval) == 1:
    interval.append(int (raw_input() ) )
counter = 0

for n in range(interval[0], interval[1] + 1):
    string = str(n)
    a = 0
    b = len(string) - 1

    reversable = True
    while a <= b:
        if not is_reversable(string[a], string[b]):
            reversable = False
            break
        
        a += 1
        b -= 1

    if reversable:
        counter += 1

print counter

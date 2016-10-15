old = raw_input()
new = raw_input()

total = 0
for i in range(97, 123):
    total += abs( new.count(chr(i)) - old.count(chr(i)) )

print total

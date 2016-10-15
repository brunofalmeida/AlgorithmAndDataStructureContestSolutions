minutes_allowed = input ()
num_chores = input ()
chores = []

for x in range (num_chores):
    chores.append (input ())

chores.sort ()
minutes = 0
counter = 0

for x in chores:
    minutes += x
    counter += 1

    if minutes > minutes_allowed:
        counter -=1
        break

print counter

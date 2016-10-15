N = input ()
votes = {"A":0, "B":0, "C":0, "D":0, "E":0, "F":0, "S":0}

for x in range (N):
    vote = raw_input ()
    if vote in "ABCDEF":
        votes [vote] += 1
    else:
        votes ["S"] += 1

print votes ["A"]
print votes ["B"]
print votes ["C"]
print votes ["D"]
print votes ["E"]
print votes ["F"]
print votes ["S"]

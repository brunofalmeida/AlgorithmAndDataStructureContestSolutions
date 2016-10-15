n = int (raw_input ())
m = int (raw_input ())

adjectives = []
nouns = []

for i in range (n):
    adjectives.append (raw_input ())
for i in range (m):
    nouns.append (raw_input ())

for a in adjectives:
    for n in nouns:
        print a, "as", n

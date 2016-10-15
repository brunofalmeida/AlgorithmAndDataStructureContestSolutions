N = int(raw_input())
T = int(raw_input())

pumpkins = []
for i in range(N):
    pumpkins.append(int(raw_input()))

pumpkins.sort()

low = 999999

for i in range(0, len(pumpkins) - T + 1):
    low = min( low,
        abs(pumpkins[i + T - 1] - pumpkins[i])
        + min(abs(pumpkins[i]), abs(pumpkins[i + T - 1])) )

print low

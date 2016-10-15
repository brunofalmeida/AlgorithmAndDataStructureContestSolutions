def getRowScore(row):
    maximum = 0

    prev = 0
    for col in range(m):
        if grid[row][col] == 1:
            prev += 1
        else:
            maximum = max(maximum, prev)
            prev = 0

    maximum = max(maximum, prev)

    return maximum


def getGridScore():
    maximum = 0
    for rowScore in rowScores:
        maximum = max(maximum, rowScore)
    return maximum


n, m, q = map(int, raw_input().strip().split())

grid = []
for i in range(n):
    grid.append(map(int, raw_input().strip().split()))

rowScores = []
for i in range(n):
    rowScores.append(getRowScore(i))

for i in range(q):
    i, j = map(int, raw_input().strip().split())

    grid[i - 1][j - 1] = 1 - grid[i - 1][j - 1]

    rowScores[i - 1] = getRowScore(i - 1)
    print getGridScore()

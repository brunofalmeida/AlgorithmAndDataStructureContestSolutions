N = int(raw_input())
M = 2 * N - 1

grid = [["a" for i in range(M)] for ii in range(M)] # [y][x]
mid = N - 1

for layer in range(1, N):
    for x in range(mid - layer, mid + layer + 1):
        grid[mid - layer][x] = grid[mid + layer][x] = chr(layer + 97)
    for y in range(mid - layer + 1, mid + layer):
        grid[y][mid - layer] = grid[y][mid + layer] = chr(layer + 97)

for y in range(M):
    print "".join(grid[y])

import sys
from collections import deque
sys.stdin = open("DATA21.txt","r")

def check(grid):
    for i in range(r):
        for j in range(c):
            if grid[i][j] != '.':
                if j+2<c:
                    if grid[i][j] == grid[i][j+1] == grid[i][j+2]:
                        return True
                    
    for j in range(c):
        for i in range(r):
            if grid[i][j] != '.' and i+2<r:
                if grid[i][j] == grid[i+1][j] == grid[i+2][j]:
                    return True
                
    return False

def erase(grid):
    new = []
    for each in grid:
        new.append(each[:])
        
    for i in range(r):
        pos = 0 #horizontal position
        
        while pos<c:
            check = grid[i][pos]
            if check != '.':
                length = 0
                
                while pos<c and grid[i][pos] == check:
                    pos += 1
                    length += 1
                    
                if length>=3:
                    for j in range(pos-length,pos):
                        new[i][j] = '.'
            else:
                pos += 1

    for j in range(c):
        pos = 0     # vertical position
        
        while pos<r:
            check = grid[pos][j]
            if check != '.':
                length = 0
                
                while pos<r and grid[pos][j] == check:
                    pos += 1
                    length += 1
                    
                if length>=3:
                    for i in range(pos-length,pos):
                        new[i][j] = '.'
            else:
                pos += 1
                
    return new

for t in range(10):
    string = ''
    r,c = map(int,raw_input().strip().split())
    
    for tt in range(5):
        state = []
        for i in range(r):
            state.append(list(raw_input().strip()))
            
        vis = set()
        queue = deque([])
        vis.add(tuple(map(tuple,state)))

        win = False
        queue.append(state)
        
        while queue:
            state = queue.popleft()
            done = True
            
            for i in range(r):
                for j in range(c):
                    if state[i][j] != '.':
                        done = False
                        
            if done:
                string += 'S'
                win = True
                break
            
            for i in range(r):
                for j in range(c):
                    new = []
                    for each in state:
                        new.append(each[:])
                        
                    if i+1<r and new[i][j] != '.' and new[i+1][j] != '.':
                        new[i][j],new[i+1][j] = new[i+1][j],new[i][j]
                        
                        if check(new):
                            new = erase(new)
                            if tuple(map(tuple,new)) not in vis:
                                vis.add(tuple(map(tuple,new)))
                                queue.append(new)
                                
            for i in range(r):
                for j in range(c):
                    new = []
                    for each in state:
                        new.append(each[:])
                        
                    if j+1<c and new[i][j] != '.' and new[i][j+1] != '.':
                        new[i][j],new[i][j+1] = new[i][j+1],new[i][j]
                        
                        if check(new):
                            new = erase(new)
                            if tuple(map(tuple,new)) not in vis:
                                vis.add(tuple(map(tuple,new)))
                                queue.append(new)

        if not win:
            string += 'N'
            
    print string

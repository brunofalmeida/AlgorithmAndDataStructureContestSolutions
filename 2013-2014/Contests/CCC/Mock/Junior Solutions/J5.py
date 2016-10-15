import sys
#sys.stdin=open("DATA.txt","r")
def main():
    r,c,t=map(int,raw_input().split())
    grid=[]
    for z in xrange(t):
        grid.append([])
        for y in xrange(r):
            grid[z].append(list(raw_input().strip()))
            for x in xrange(c):
                if grid[z][y][x]=="A":
                    sz=z
                    sy=y
                    sx=x
                elif grid[z][y][x]=="B":
                    ez=z
                    ey=y
                    ex=x
    dp=[[[999999 for x in xrange(c)]for y in xrange(r)]for z in xrange(t)]
    queue=[[sz,sy,sx]]
    dp[sz][sy][sx]=0
    while len(queue)>0:
        z,y,x=queue.pop(0)
        for i in xrange(t):
            if dp[i][y][x]==999999 and grid[i][y][x]<>"X":
                dp[i][y][x]=dp[z][y][x]+1
                queue.append([i,y,x])
        if y-1>=0 and dp[z][y-1][x]==999999 and grid[z][y-1][x]<>"X":
            dp[z][y-1][x]=dp[z][y][x]+1
            queue.append([z,y-1,x])
        if y+1<r and dp[z][y+1][x]==999999 and grid[z][y+1][x]<>"X":
            dp[z][y+1][x]=dp[z][y][x]+1
            queue.append([z,y+1,x])
        if x-1>=0 and dp[z][y][x-1]==999999 and grid[z][y][x-1]<>"X":
            dp[z][y][x-1]=dp[z][y][x]+1
            queue.append([z,y,x-1])
        if x+1<c and dp[z][y][x+1]==999999 and grid[z][y][x+1]<>"X":
            dp[z][y][x+1]=dp[z][y][x]+1
            queue.append([z,y,x+1])
    if dp[ez][ey][ex]==999999:
        print -1
    else:
        print dp[ez][ey][ex]
main()

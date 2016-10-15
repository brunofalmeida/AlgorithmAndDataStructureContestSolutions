#This type of question is known as the state searching question.
#You are given a starting state and an ending state.
#The question being asked usually is to find the minimum number of moves required to transform the starting state to the ending state.
#One famous question of this type is Tower of Hanoi, and it has been studied intensively, thus a recursive solution is discovered.
#One other example could be Rubik's cube.
#However, you will not have enough time during a contest to figure out an actual "solution" to this type of question, and in fact, for most of them, they don't have a solution...
#Therefore, the strategy to solve this type of question is BFS.
#Consider the states being vertexes, and the ability of changing one state to another as edges,
#it can be modeled by an unweighted-undirected graph.
#You are simply required to find the shortest path between vertex S and vertex T.

#For this 2048 problem, there are some slight differences.
#1. The ending state is unknown(There is more than one ending state).
#2. Instead of minimum number of moves, you are asked to find the maximum score.
#However, the algorithm used to solve 2048 is still BFS...

#The complexity for such a solution is O(b^d) where b is the branching factor, and d is the depth.
#For this problem, b is 4, so as long as d<=10(for Python only), the algorithm will be fast enough.

import sys
#sys.stdin=open("DATA.txt","r")
def main():
    for QQ in xrange(5):
        grid=[]
        m=0
        for i in xrange(4):
            grid.append(map(int,raw_input().split()))
            m=max(m,max(grid[i]))
        temp=tuple(map(tuple,grid))      #One line 2D list to 2D tuple
        flag=set(temp)                   #See Python documentation for set
        q=[[grid,m]]
        ans=m
        while len(q)>0:
            state,m=q.pop(0)
            ans=max(ans,m)
            if ans==2048:
                break
            #Move left
            temp=map(list,state)    #Create a copy of state in one line
            mm=m
            for j in xrange(1,4):
                for i in xrange(4):
                    pos=j
                    while pos-1>=0 and temp[i][pos-1]==0:
                        pos-=1
                    if pos-1>=0 and temp[i][pos-1]==temp[i][j]:
                        pos-=1
                    if pos<>j:
                        val=temp[i][j]
                        if temp[i][pos]==temp[i][j]:
                            val<<=1          #Same as val*=2
                        temp[i][pos]=val
                        mm=max(mm,temp[i][pos])
                        temp[i][j]=0
            x=tuple(map(tuple,temp))
            if x not in flag:          #One state is only visited once; the same idea as any BFS
                flag.add(x)
                q.append([temp,mm])
            #Move right
            temp=map(list,state)
            mm=m
            for j in xrange(2,-1,-1):
                for i in xrange(4):
                    pos=j
                    while pos+1<4 and temp[i][pos+1]==0:
                        pos+=1
                    if pos+1<4 and temp[i][pos+1]==temp[i][j]:
                        pos+=1
                    if pos<>j:
                        val=temp[i][j]
                        if temp[i][pos]==temp[i][j]:
                            val<<=1
                        temp[i][pos]=val
                        mm=max(mm,temp[i][pos])
                        temp[i][j]=0
            x=tuple(map(tuple,temp))
            if x not in flag:
                flag.add(x)
                q.append([temp,mm])
            #Move up
            temp=map(list,state)
            mm=m
            for i in xrange(1,4):
                for j in xrange(4):
                    pos=i
                    while pos-1>=0 and temp[pos-1][j]==0:
                        pos-=1
                    if pos-1>=0 and temp[pos-1][j]==temp[i][j]:
                        pos-=1
                    if pos<>i:
                        val=temp[i][j]
                        if temp[pos][j]==temp[i][j]:
                            val<<=1
                        temp[pos][j]=val
                        mm=max(mm,temp[pos][j])
                        temp[i][j]=0
            x=tuple(map(tuple,temp))
            if x not in flag:
                flag.add(x)
                q.append([temp,mm])
            #Move down
            temp=map(list,state)
            mm=m
            for i in xrange(2,-1,-1):
                for j in xrange(4):
                    pos=i
                    while pos+1<4 and temp[pos+1][j]==0:
                        pos+=1
                    if pos+1<4 and temp[pos+1][j]==temp[i][j]:
                        pos+=1
                    if pos<>i:
                        val=temp[i][j]
                        if temp[pos][j]==temp[i][j]:
                            val<<=1
                        temp[pos][j]=val
                        mm=max(mm,temp[pos][j])
                        temp[i][j]=0
            x=tuple(map(tuple,temp))
            if x not in flag:
                flag.add(x)
                q.append([temp,mm])
        print ans 
main()

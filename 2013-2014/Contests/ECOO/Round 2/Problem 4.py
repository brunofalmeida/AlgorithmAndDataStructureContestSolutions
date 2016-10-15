import sys
sys.stdin= open("DATA42.txt","r")

for i in range(10):
    graph=[]
    for i in range(6):
        graph.append(raw_input().strip())

    visit = [[False for i in range(6)]for j in range(6)]
    rotation = [[ [] for i in range(6)]for j in range(6)]
    for i in range(6):
        visit[0][i]=True
        visit[i][0] = True
        visit[i][-1]=True
        visit[-1][i] = True

    t=[]
    queue=[]
    for i in range(6):
        for j in range(6):
            if graph[i][j]=="S":
                queue.append([i-1,j,0])
            elif graph[i][j] == "T":
                t.append([i,j])
    complete=[False for i in range(len(t))]

    while len(queue)>0:
        u= queue.pop(0)
        temp=False
        for i in range(len(t)):
            if [u[0],u[1]]==t[i]:
                complete[i]=True
                temp= True
        if graph[u[0]][u[1]]=="S":
            temp=True
        if not temp:       
        
            moves=[]
            if u[2]==0:
                for i in range(1,u[0]):
                    moves.append(graph[i][u[1]])
            elif u[2]==1:
                for i in range(u[1]+1,5):
                    moves.append(graph[u[0]][i])
            elif u[2]==2:
                for i in range(u[0]+1,5):
                    moves.append(graph[i][u[1]])
            elif u[2]==3:
                for i in range(1,u[1]):
                    moves.append(graph[u[0]][i])

            moves= list(set(moves))
            
            for i in range(len(moves)):
                if moves[i]=="U":
                    if not (visit[u[0]-1][u[1]] and u[2] in rotation[u[0]-1][u[1]]) and graph[u[0]-1][u[1]]!=".":
                        visit[u[0]-1][u[1]] = True
                        rotation[u[0]-1][u[1]].append(u[2])
                        queue.append([u[0]-1,u[1],u[2]])
                elif moves[i] =="D":
                    if not (visit[u[0]+1][u[1]] and u[2] in rotation[u[0]+1][u[1]]) and graph[u[0]+1][u[1]]!=".":
                        visit[u[0]+1][u[1]] = True
                        rotation[u[0]+1][u[1]].append(u[2])
                        queue.append([u[0]+1,u[1],u[2]])
                elif moves[i] =="R":
                    if not (visit[u[0]][u[1]+1] and u[2] in rotation[u[0]][u[1]+1]) and graph[u[0]][u[1]+1]!=".":
                        visit[u[0]][u[1]+1] = True
                        rotation[u[0]][u[1]+1].append(u[2])
                        queue.append([u[0],u[1]+1,u[2]])
                elif moves[i] =="L":
                    if not (visit[u[0]][u[1]-1] and u[2] in rotation[u[0]][u[1]-1]) and graph[u[0]][u[1]-1]!=".":
                        visit[u[0]][u[1]-1] = True
                        rotation[u[0]][u[1]-1].append(u[2])
                        queue.append([u[0],u[1]-1,u[2]])
                elif moves[i] == "C":
                    tempDirect=u[2]+1
                    if tempDirect>3:
                        tempDirect=0

                    if tempDirect not in rotation[u[0]][u[1]]:
                        queue.append([u[0],u[1],tempDirect])
                        rotation[u[0]][u[1]].append(tempDirect)
                elif moves[i] == "B":
                    tempDirect=u[2]-1
                    if tempDirect<0:
                        tempDirect=3

                    if tempDirect not in rotation[u[0]][u[1]]:
                        queue.append([u[0],u[1],tempDirect])
                        rotation[u[0]][u[1]].append(tempDirect)
                    
    string = ""
    for i in range(len(complete)):
        
        if complete[i]:
            string= string+"T"
        else:
            string = string+"F"


    print string



            
            

                

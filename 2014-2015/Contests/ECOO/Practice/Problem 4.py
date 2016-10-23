import sys
sys.stdin = open("DATA42.txt","r")
done = True
moves = [[0,1],[1,0],[-1,0],[0,-1],[1,1],[-1,1],[1,-1],[-1,-1]]
def find(x,y,pos,word):
    global done
    #print pos,len(word)
    if (pos == len(word)):
        done = True
        return
    for mx,my in moves:
        if 0<=x+mx<4 and 0<=y+my<4 and not flag[x+mx][y+my] and board[x+mx][y+my] == word[pos]:
           flag[x+mx][y+my] = True
           find(x+mx,y+my,pos+1,word)
           flag[x+mx][y+my] = False
for test in range(5):
    good = 0
    nfound = 0
    tshort = 0
    score = 0
    rpt = 0
    board = []
    seen = []
    for z in range(4):
        board.append(list(raw_input().strip()))
    
    n = int(raw_input())
    words = []
    for i in range(n):
        done = False
        word = raw_input().strip()
    
        for x in range(4):
            for y in range(4):
                flag = [[False for zz in range(4)]for zz in range(4)]
                find(x,y,0,word)

        if len(word)>=3:
            if (word not in seen):
                if done:
                    l = len(word)
                    if l == 3 or l == 4:
                        score += 1
                    elif l == 5:
                        score += 2
                    elif l == 6:
                        score += 3
                    elif l == 7:
                        score += 4
                    else:
                        score += 11
                    good += 1
                else:
                    nfound+=1
            else:
                rpt+=1
        else:
            tshort+=1
        seen.append(word)

    print "Your score:",score,"("+str(good),"good,",nfound,"not found,",tshort,"too short,",rpt,"repeated)"

import sys
sys.stdin = open("DATA21.txt","r")

def area(x1,y1,x2,y2,x3,y3):
    return abs(float((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2)))/2

def checkT(x1,y1,x2,y2,x3,y3,px,py):
    area1 = area(x1,y1,x2,y2,x3,y3)
    a1 = float(area(px,py,x2,y2,x3,y3))
    a2 = float(area(x1,y1,px,py,x3,y3))
    a3 = float(area(x1,y1,x2,y2,px,py))
    ##print a1+a2+a3,area1
    if (a1+a2+a3) == area1:
        return True
    else:
        return False
    
def checkR(x1,y1,x2,y2,x3,y3,x4,y4,px,py):
    if min(x1,x2,x3,x4) <= px <= max(x1,x2,x3,x4):
        if min(y1,y2,y3,y4) <= py <= max(y1,y2,y3,y4):
            return True
    return False

for test in range(10):
    B,H = map(int,raw_input().strip().split())
    colors = raw_input().strip().split()
    ans = [0 for i in range(len(colors))]
    n = int(raw_input().strip())
    shapes = []
    
    for i in range(n):
        row = list(raw_input().strip().split())
        shapes.append(row)
    points = []
    
    for i in range(500):
        r,c = map(int,raw_input().strip().split())
        count = 0
        #print "point: ", r,c
        for shape in shapes:
            ty = shape[0]
            if ty == 'T':
                x1 = int(shape[1])
                y1 = int(shape[2])
                b = int(shape[3])
                x2 = x1+B*b
                y2 = y1
                x3 = x1
                y3 = y1 + b*H

                ##print "area:",area(x1,y1,x2,y2,x3,y3)
                if checkT(x1,y1,x2,y2,x3,y3,r,c):
                   ## print x1,y1
                   ## print x2,y2
                   ## print x3,y3
                    count += 1

            else:
                x1 = int(shape[1])
                y1 = int(shape[2])
                b = int(shape[3])
                h = int(shape[4])
                x2 = x1
                y2 = y1+H*h
                x3 = x1+b*B
                y3 = y1
                x4 = x3
                y4 = y2
                if checkR(x1,y1,x2,y2,x3,y3,x4,y4,r,c):
                    count += 1
        #print count
            
        ans[count%len(colors)]+= 1
    for i in range(len(ans)):
        print colors[i]+':'+str(ans[i]),
    print
                
                
    ##    r = row[1]
    ##    c = row[2]
    ##    if (shape == 'R'):
    ##        w = int(row[3])
    ##        h = int(row[4])
    ##    else:
    ##        b = int(row[3])
    ##        h = int(b/B*H)
    ##    print r

            

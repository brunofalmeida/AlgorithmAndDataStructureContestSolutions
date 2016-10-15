import sys
import random
for test in range(1,11):
    sys.stdout = open("PurchasingPresents."+str(test)+".in","w")
    if test == 1:
        N = 5
        C = 45.00
        L = [8.32,8.31,8.30,2.65,4.00]
    if test == 2:
        N = 1
        C = 0.05
        L = [0.05]
    if test == 3:
        N = 4
        C = 90415.11
        L = [30000.00,3000.00,300.00,50000.00]
    if test == 4:
        N = 15
        C = 90.01
        L = [random.uniform(5.5,6.5) for i in range(N)]
    if test == 5:
        N = 7
        C = 21.98
        L = [3.14 for i in range(N)]
    if test == 6:
        N = 6
        C = 18.05
        L = [3.01 for i in range(N)]
    if test == 7:
        N = 6
        C = 1.99
        L = [0.20,0.49,0.38,0.44,0.25,0.24]
    if test == 8:
        N = 40
        C = 271.82
        L = [random.uniform(2,10) for i in range(N)]
        while sum(L) > C:
            L = [random.uniform(2,10) for i in range(N)]
    if test == 9:
        N = 460
        C = 230000.00
        L = [random.uniform(0,1000) for i in range(N)]
    if test == 10:
        N = 100
        C = 50.00
        L = [random.uniform(2,3) for i in range(N)]

    print N
    print format(C,'.2f')
    for num in L:
        print format(round(num,2),'.2f')
    sys.stdout.close()
    

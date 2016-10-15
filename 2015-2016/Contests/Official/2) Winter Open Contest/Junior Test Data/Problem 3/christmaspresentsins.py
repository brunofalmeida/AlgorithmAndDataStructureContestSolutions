import sys
import random
alphabet = 'abcdefghijklmnopqrstuvwxyz'
for test in range(1, 11):
    sys.stdout = open("ChristmasPresents." + str(test) + ".in", "w")
    if test == 1:
        p = 2
        t = 2
        ps = [['Joystick',41.99],['Old Printer',29.99]]
        ts = [['Mr. Fong',45],['Mr. Bradshaw',44]]
    if test == 2:
        p = 4
        t = 2
        ps = [['Random Assortment of Chocolates',10.51],['Black Cat',20.15],
              ['Diamond Sword',999.99],['Carton of Egg Nog',1.50]]
        ts = [['Ms. Slinko',80],['Mr. Shirbegi',79]]
    if test == 3:
        p = 4
        t = 4
        ps = [['Map of Canada',2.15],['Salsa Dancing Class',30.00],
              ['Particle Accelerator',20000000000.00],['Person who can play the oboe',450.00]]
        ts = [['Mr. Peterson',12],['Mr. Wilson',14],['Ms. Pierson',20],['Mr. Fong',88]]
    if test == 4:
        p = 5
        t = 4
        ps = [['Protractor',0.99],['Compass',1.19],['Ruler',1.00],['GDC',84.99],['Pack of Graph Paper',3.00]]
        ts = [['Mr. Pop',57],['Ms. McLaren',49],['Ms. Orr',50],['Mr. Rhamey',39]]
    if test == 5:
        p = 6
        t = 6
        ps = [['Flask',5.99],['Graduated Cylinder',5.89],['Dissectable Rat',10.12],
              ['Spring Scale',4.90],['Bottle of Caesium',40.59],['Tank of Helium',36.99]]
        ts = [['Mr. Diljohn',90],['Ms. Marin',91],['Ms. Axon',67],['Mr. Ashworth',70],
              ['Ms. Tatulea',65],['Ms. Masterton',80]]
    if test == 6:
        p = 8
        t = 8
        ps = []
        ts = []
        for Q in range(p):
            name = [random.choice(alphabet) for i in range(random.randint(4,10))]
            n = ''.join(name)
            cost = round(random.uniform(1,100000),2)
            ps.append([n,cost])
        for Q in range(t):
            teach = [random.choice(alphabet) for i in range(random.randint(4,10))]
            h = ''.join(teach)
            rate = random.randint(1,100)
            ts.append([h,rate])
    if test == 7:
        p = 10
        t = 10
        ps = []
        ts = []
        for Q in range(p):
            name = [random.choice(alphabet) for i in range(random.randint(4,10))]
            n = ''.join(name)
            cost = round(random.uniform(1,100000),2)
            ps.append([n,cost])
        for Q in range(t):
            teach = [random.choice(alphabet) for i in range(random.randint(4,10))]
            h = ''.join(teach)
            rate = random.randint(1,100)
            ts.append([h,rate])
    if test == 8:
        p = 14
        t = 13
        ps = []
        ts = []
        for Q in range(p):
            name = [random.choice(alphabet) for i in range(random.randint(4,10))]
            n = ''.join(name)
            cost = round(random.uniform(1,100000),2)
            ps.append([n,cost])
        for Q in range(t):
            teach = [random.choice(alphabet) for i in range(random.randint(4,10))]
            h = ''.join(teach)
            rate = random.randint(1,100)
            ts.append([h,rate])
    if test == 9:
        p = 17
        t = 15
        ps = []
        ts = []
        for Q in range(p):
            name = [random.choice(alphabet) for i in range(random.randint(4,10))]
            n = ''.join(name)
            cost = round(random.uniform(1,100000),2)
            ps.append([n,cost])
        for Q in range(t):
            teach = [random.choice(alphabet) for i in range(random.randint(4,10))]
            h = ''.join(teach)
            rate = random.randint(1,100)
            ts.append([h,rate])
    if test == 10:
        p = 20
        t = 20
        ps = []
        ts = []
        for Q in range(p):
            name = [random.choice(alphabet) for i in range(random.randint(4,10))]
            n = ''.join(name)
            cost = round(random.uniform(1,100000),2)
            ps.append([n,cost])
        for Q in range(t):
            teach = [random.choice(alphabet) for i in range(random.randint(4,10))]
            h = ''.join(teach)
            rate = random.randint(1,100)
            ts.append([h,rate])
    print p
    print t
    for present in ps:
        print present[0]
        print format(present[1],'.2f')
    for teacher in ts:
        print teacher[0]
        print teacher[1]
    sys.stdout.close()
    

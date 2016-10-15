import sys
for test in range(1,11):
    sys.stdin = open("PurchasingPresents."+str(test)+".in","r")
    sys.stdout = open("PurchasingPresents."+str(test)+".out","w")

    #But in real life, Fardin's always broke
    presents = int(raw_input())
    money = float(raw_input())

    for i in range(presents):
        cost = float(raw_input())
        money -= cost

    if money < 0:
        print "Fardin's broke"
    else:
        print money
    sys.stdout.close()

plist = ["A", "B", "C", "D", "E"]

while True:
    b = int (raw_input ())
    n = int (raw_input ())
    
    if b == 1:
        for i in range (n):
            old = plist [:]
            plist [0:4] = old [1:5]
            plist [4] = old [0]
    
    elif b == 2:
        for i in range (n):
            old = plist [:]
            plist [0] = old [4]
            plist [1:5] = old [0:4]
    
    elif b == 3:
        for i in range (n):
            old = plist [:]
            plist [0] = old [1]
            plist [1] = old [0]
    
    elif b == 4:
        for x in plist [0: 4]:
            print x,
        print plist [4]
        break

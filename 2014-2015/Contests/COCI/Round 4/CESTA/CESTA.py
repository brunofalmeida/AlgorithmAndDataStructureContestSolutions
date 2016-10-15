##import sys
##sys.stdin = open("cesta.dummy.in.3", "r")


N = raw_input()

strList = list(N)
intList = map(int, strList)

if "0" in strList and sum(intList) % 3 == 0:    # multiple of 30
    strList.sort()
    strList.reverse()
    output = ""
    for i in strList:
        output += i
    print output

else:
    print -1

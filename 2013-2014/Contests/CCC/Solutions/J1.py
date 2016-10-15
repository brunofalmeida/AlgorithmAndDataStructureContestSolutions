import sys
#sys.stdin=open("DATA.txt","r")
def main():
    a,b,c=int(raw_input()),int(raw_input()),int(raw_input())
    if a==60 and b==60 and c==60:
        print "Equilateral"
    elif a+b+c<>180:
        print "Error"
    elif a==b or a==c or b==c:
        print "Isosceles"
    else:
        print "Scalene"
main()

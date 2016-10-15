import sys
#sys.stdin=open("DATA.txt","r")
def main():
    n=int(raw_input())
    a=b=100
    for i in xrange(n):
        x,y=map(int,raw_input().split())
        if x>y:
            b-=x
        elif y>x:
            a-=y
    print a
    print b
main()

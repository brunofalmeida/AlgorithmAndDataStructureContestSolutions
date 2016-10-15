import sys
#sys.stdin=open("DATA.txt","r")
def main():
    n=input()
    a=[]
    for i in xrange(n):
        a.append(list(raw_input().strip()))
    for i in xrange(n-1,-1,-1):
        if not n&1^i&1:
            a[i].reverse()
        for each in a[i]:
            sys.stdout.write(each)
main()

import sys
#sys.stdin=open("DATA.txt","r")
def main():
    t=list(raw_input())
    t.reverse()
    p=list(raw_input())
    x=len(p)
    for i in xrange(len(t)):
        if t[i:i+x]==p:
            print len(t)-i
            break
    else:
        print -1
main()

import sys
#sys.stdin=open("DATA.txt","r")
def main():
    n=int(raw_input())
    graph={}
    a=raw_input().split()
    b=raw_input().split()
    yes=True
    for i in xrange(n):
        if a[i]==b[i]:
            yes=False
            break
        if a[i] in graph:
            if graph[b[i]]<>a[i]:
                yes=False
                break
            graph[a[i]]=b[i]
        if b[i] in graph:
            if graph[b[i]]<>a[i]:
                yes=False
                break
        if a[i] not in graph:
            graph[a[i]]=b[i]
    if yes:
        print "good"
    else:
        print "bad"
main()

import sys
#sys.stdin=open("DATA.txt","r")
def main():
    n=int(raw_input())
    a=map(int,raw_input().split())
    ans=0
    for i in xrange(n):
        x=a[i]
        pos=i
        q=e=False
        while pos+1<n and a[pos+1]<x:
            pos+=1
            x=a[pos]
            q=True
        while pos+1<n and a[pos+1]==x:
            pos+=1
            x=a[pos]
        while pos+1<n and a[pos+1]>x:
            pos+=1
            x=a[pos]
            e=True
        if q and e:
            ans=max(ans,pos-i+1)
    print ans
main()

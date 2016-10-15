import sys
#sys.stdin=open("DATA.txt","r")
def parse(a):
    l=int(a[:2])%12*60+int(a[3:5])
    if a[5:7]=="PM":
        l+=720
    r=int(a[8:10])%12*60+int(a[11:13])
    if a[13:15]=="PM":
        r+=720
    return l,r
def main():
    l,r=parse(raw_input())
    ans=0
    out=""
    for i in xrange(int(raw_input())):
        temp=raw_input()
        a,b=parse(temp)
        if l>b or r<a:
            continue
        elif a<=l and b>=r:
            ans=r-l
            out=temp
            break
        if min(r-a,b-l)>ans:
            ans=min(r-a,b-l)
            out=temp
    if out=="":
        print "Call in a sick day."
    else:
        print out
main()

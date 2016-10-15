import sys
#sys.stdin=open("DATA.txt","r")
def main():
    h=input()
    m=(input()+h)%360
    s=(input()+m)%360
    a=int(h/30.0)
    if a==0:
        a=12
    print "%.2d:%.2d:%.2d"%(a,m/6.0,round(s/6.0))
main()

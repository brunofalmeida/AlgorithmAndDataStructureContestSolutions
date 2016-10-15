import sys
#sys.stdin=open("DATA.txt","r")
def main():
    a=int(raw_input())
    b=int(raw_input())
    r=int(raw_input())
    if a>r:
        print "Bob overdoses on day 1."
    elif a/2.0+b>r:
        print "Bob overdoses on day 2."
    else:
        print "Bob never overdoses."
main()

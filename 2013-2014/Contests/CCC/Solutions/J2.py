import sys
#sys.stdin=open("DATA.txt","r")
def main():
    n=int(raw_input())
    cnt={"A":0,"B":0}
    for each in list(raw_input().strip()):
        cnt[each]+=1
    if cnt["A"]>cnt["B"]:
        print "A"
    elif cnt["A"]==cnt["B"]:
        print "Tie"
    else:
        print "B"
main()

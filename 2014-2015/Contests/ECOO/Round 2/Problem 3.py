import sys
sys.stdin = open("DATA31.txt","r")

for i in range(10):       
    n,t = map(int,raw_input().strip().split())
    print n*2-1

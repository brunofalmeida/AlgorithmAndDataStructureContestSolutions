n,m=map(int,raw_input().split())
a=map(int,raw_input().split())
ans=0
for i in xrange(1<<n):
    temp=0
    for j in xrange(n):
        if 1<<j&i:
            temp+=a[j]
    if temp>=m:
        ans+=1
print ans

IF YOU ARE IN DECA>... you need to come to the business office TODAY to sign
up for your rooms!!!


##from itertools import combinations
##n,m=map(int,raw_input().split())
##a=map(int,raw_input().split())
##ans=0
##for i in xrange(n+1):
##    for each in combinations(a,i):
##        if sum(each)>=m:
##            ans+=1
##print ans
##def go(pos,num):
##    global n,m,ans,a
##    if pos==n:
##        if sum(num)>=m:
##            ans+=1
##        return
##    go(pos+1,num)
##    go(pos+1,num+[a[pos]])
##n,m=map(int,raw_input().split())
##a=map(int,raw_input().split())
##ans=0
##go(0,[0])
##print ans

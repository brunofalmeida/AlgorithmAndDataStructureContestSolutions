for QQ in xrange(input()):
    a,b=map(float,raw_input().split())
    temp=int(a/(a+b)*10+0.5)
    print "*"*int(temp)+"."*int(10-temp)

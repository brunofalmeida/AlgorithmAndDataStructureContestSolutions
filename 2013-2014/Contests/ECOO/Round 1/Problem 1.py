DEBUG = False

infile = open ("DATA10.txt", "r")

for i in range (10):
    d, h, m = map (int, infile.readline ().strip ().split () )
    s = ((d - 1) * 24 * 60 * 60) + (h * 60 * 60) + (m * 60)

    s = s*86400/88642.663
    days = s/3600/24
    d = int(s/3600/24)
    days -= int(s/3600/24)
    hours = days*24
    h = hours/1
    hours = hours%1
    minutes =(hours*60)
    print "Days %s, %02d:%02d"%(d+1,int(h),int(minutes))

##    if DEBUG:
##        print

infile.close ()

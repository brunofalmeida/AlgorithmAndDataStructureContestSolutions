import sys
sys.stdin = open("DATA11.txt")
season_name = raw_input().strip()
ans = []
totbat = 0
totgames = 0
tot1 = 0
tot2 = 0
tot3 = 0
tothr = 0
totr = 0
toth = 0
for i in range(10):
    line = raw_input().strip().split()
    name = line.pop(0)
    line = map(int,line)
    slug = 0
    bat = 0
    #games played, at bats, runs, hits(total),2 base, 3 base, home runs
    gamesplayed = line[0]
    atbats = line[1]
    runs = line[2]
    hits = line[3]
    base2 = line[4]
    base3 = line[5]
    hr = line[6]
    base1 = hits - base2-base3-hr
    tot1 += base1
    tot2 += base2
    tot3 += base3
    tothr += hr
    totr += runs
    toth += hits
    totgames += gamesplayed
    totbat += atbats
    s = float(base1+2*base2+3*base3+4*hr)/atbats
    b = float(base1+base2+base3+hr)/atbats
    ansline = []
    ansline.append(name+":")
    ansline.append(b)
    ansline.append(s)
    ans.append(ansline)

print season_name
print "===================="
for i in ans:
    print i[0],str(format(round(i[1], 3), ".3f"))[1:],str(format(round(i[2],3), ".3f"))[1:]
print "===================="
tots = float(tot1+2*tot2+3*tot3+4*tothr)/totbat
totb = float(tot1+tot2+tot3+tothr)/totbat
print "Big 10 Av:",str(format(round(totb,3),".3f"))[1:],str(format(round(tots,3),".3f"))[1:]

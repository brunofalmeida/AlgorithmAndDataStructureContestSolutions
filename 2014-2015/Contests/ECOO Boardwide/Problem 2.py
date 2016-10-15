import sys
sys.stdin = open("DATA21.txt","r")

for i in range(10):
    w = int(raw_input())
    words = raw_input().strip().split()
    cnt = 0
    line = True
    for word in words:
        length = len(word)
        if length > w:
            if not line:
                print
            sections = []
            while len(word) > 0:
                sections.append(word[:w])
                word = word[w:]
            for section in sections[:-1]:
                print section
            print sections[-1],
            cnt = len(sections[-1]) + 1
                
        elif length+cnt>w:
            print
            print word,
            cnt = length + 1
            
        else:
            print word,
            cnt += length + 1
            
        if line:
            line = False
    print
    print "====="

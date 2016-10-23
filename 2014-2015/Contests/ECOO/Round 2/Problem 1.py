import sys
sys.stdin = open("DATA11.txt","r")

for i in range(10):
    mode = raw_input().strip()
    
    if mode == "encode":
        words = raw_input().strip().split()
        lengths = map(len, words)
        n = len(words)
        newstring = ""
        while 1:
            done = True
            for i in range(n):
                if (len(words[i])):
                    done = False
                    newstring+=words[i][0]
                    words[i] = words[i][1:]
            if done:
                break

        newStringList = []
        for length in lengths:
            newStringList.append(newstring[:length])
            newstring = newstring[length:]

        print " ".join(newStringList)
        
    else:
        words = raw_input().strip().split()
        n = len(words)
        lengths = map(len,words)
        string = ''.join(words)
        newWords = ["" for i in range(n)]
        while string:
            for i in range(n):
                if len(newWords[i])!=lengths[i]:
                    newWords[i] += string[0]
                    string = string[1:]
        print ' '.join(newWords)
        

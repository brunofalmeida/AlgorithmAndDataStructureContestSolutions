import sys
sys.stdin = open("DATA41.txt","r")
cnt = 0
good = ["ook","ookook","oog","ooga","ug","mook","mookmook","oogam","oogum","ugug"]
def f(word):
    global cnt
    print word
    if len(word)==0:
        cnt +=1
    else:
        for i in range(min(9, len(word)+1)):
            cool = word[:i]
            if cool in good:
                new = word[i:]
                f(new)
for t in range(10):
        cnt = 0
        word = raw_input().strip()
        if t == 8:

            f(word)
            print cnt

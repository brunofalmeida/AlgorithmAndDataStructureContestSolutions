# file input
import sys
sys.stdin = open("DATA21.txt","r")

# 10 test cases
for i in range(10):
    # input width and words to wrap
    w = int(raw_input())
    words = raw_input().strip().split()

    # number of characters already used on the current line
    cnt = 0

    # can continue printing on current line
    line = True

    # for each word
    for word in words:

        # length of word
        length = len(word)

        # if current word length is greater than total width
        if length > w:
            
            # if we cannot print on the current line, go to the next line
            if not line:
                print

            # break up the word into sections (1 on each line)
            sections = []

            # while there is still part of the word left
            while len(word) > 0:

                # add a section with w characters
                sections.append(word[:w])

                # remove the section from word
                word = word[w:]

            # print every section (except the last one) on its own line
            for section in sections[:-1]:
                print section

            # print the last section, keeping next print on the same line
            print sections[-1],

            # set character count on the current line (add 1 for space)
            cnt = len(sections[-1]) + 1

        # if current word does not fit on line
        elif (length + cnt) > w:
            
            # print word on a new line, keeping next print on the same line
            print
            print word,

            # set character count on the current line (add 1 for space)
            cnt = length + 1

        # if current word fits on line
        else:
            # print word on the same line, keeping next print on the same line
            print word,

            # increase character count on the current line (add 1 for space)
            cnt += length + 1

        # need a new line
        if line:
            line = False

    # print a new line, and characters between test cases
    print
    print "====="

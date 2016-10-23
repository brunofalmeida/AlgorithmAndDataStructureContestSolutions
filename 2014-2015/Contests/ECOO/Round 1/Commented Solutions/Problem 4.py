# This problem involves recursive DP (dynamic programming) using memoization,
# a technique used to store the result of a calculations so that they do not have to be repeated later,
# making the algorithm more time efficient and reducing its complexity
# http://en.wikipedia.org/wiki/Memoization


# recursive function
# returns number of possible combinations
def recurse(word):
    # we have already went through the original string and used every letter in a word,
    # so one possibility has been found
    if len(word) == 0:
        return 1

    # number of possible combinations with current string
    total = 0

    # for each possible word length (ranges from 2 to 8 letters - see 'good' list below)
    for i in range(2, min(9, len(word) + 1)):

        # get substring of length i
        cool = word[0:i]

        # if substring is a valid word
        if cool in good:

            # remove substring for next recursive call
            newWord = word[i:]

            # check if current string has already been examined
            # if so, use the previous result instead of of recalculating
            if memo.has_key(newWord):
                total += memo[newWord]

            # otherwise, calculate the result by recursing on the new string,
            # and store the result for future use
            else:
                memo[newWord] = recurse(newWord)
                total += memo[newWord]

    # return number of possible combinations
    return total


# file input
import sys
sys.stdin = open("DATA41.txt", "r")

# dictionary used to store memoized results
# key is a string, value is a number (of possible combinations)
memo = {}

# list of valid words
good = ["ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"]

# 10 test cases
for i in range(10):

    # input string of words
    word = raw_input().strip()

    # output result of recursive function
    print recurse(word)

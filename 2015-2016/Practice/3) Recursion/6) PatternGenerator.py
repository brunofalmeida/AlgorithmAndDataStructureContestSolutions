# http://wcipeg.com/problems/desc/ccc96s3


# recursive function
# base is the bit pattern already created
# n is the number of digits left to add
# k is the number of 1s left to add
def pattern(base, n, k):

    # if there are no more digits to add,
    # print out what we already have
    if n == 0:
        print base

    # if the number of digits is equal to the number of 1s,
    # the remaining digits to add can only be 1s,
    # so recurse by adding a 1
    elif n == k:
        # add a 1 to the base pattern, subtract a digit, subtract a 1
        pattern(base + "1", n - 1, k - 1)
        
    # if there are no more 1s to add,
    # only add 0s
    elif k == 0:
        # add a 0 to the base pattern, subtract a digit, do not subtract a 1
        pattern(base + "0", n - 1, k)

    # otherwise, the remaining digits are a combination of 0s and 1s,
    # so recurse in both cases
    # the output must be in descending order,
    # so add a 1 first
    else:
        pattern(base + "1", n - 1, k - 1)
        pattern(base + "0", n - 1, k)




# input number of pattern sets
numPairs = int(raw_input())

# for each set
for i in range(numPairs):
    
    # input number of digits and number of 1s
    n, k = map(int, raw_input().strip().split())

    # beginning of output
    print "The bit patterns are"

    # call recursive function
    # base is a blank string because we haven't created any pattern yet
    pattern("", n, k)

    # print a blank line between each set
    print

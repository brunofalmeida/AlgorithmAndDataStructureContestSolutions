# file input
import sys
sys.stdin = open("DATA01.txt", "r")

# 5 test cases
for test in range(5):
    
    # input toonies, loonies, quarters, dimes, nickels
    a, b, c, d, e = map(int, raw_input().strip().split())

    # print number of cents
    print ( (200 * a) + (100 * b) + (25 * c) + (10 * d) + (5 * e) )

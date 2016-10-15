##DEBUG = True
##
##def get_dec (bin):
##    sum = 0
##    for i in range (len (bin) - 1, -1, -1):
##        sum += int (bin [i]) * (2 ** i)
##    return sum
##
##def get_binary (line, AT, CG):
##    binary = ""
##
##    for x in line:
##        if x == "A" or x == "T":
##            binary += AT
##        elif x == "C" or x == "G":
##            binary += AT
##
##    return binary
##
##def is_valid (line, AT, CG):
##    binary = get_binary (line, AT, CG)
##
##    a = 0
##    i = 0
##    while True:
##        if get_dec (binary [i: i + 8]) == 32 or 65 <= get_dec (binary [i: i + 8]) <= 90:
##            a = i
##            break
##
##        if i == 6:
##            return False, 0, 0
##        i += 1
##
##    b = 7
##    i = len (line) - 1
##    while True:
##        if get_dec (binary [i - 7: i + 1]) == 32 or 65 <= get_dec (binary [i - 7: i + 1]) <= 90:
##            b = i
##            break
##
##        if i == len (line) - 7:
##            return False, 0, 0
##        i -= 1
##
##    if (b - a) % 8 != 7:
##        return False, 0, 0
##
##    return True, a, b
##
##def get_string (binary, a, b):
##    string = ""
##    for i in range (a, b - 7, 8):
##        string += chr (get_dec (binary [i: i + 8]))
##    return string
##    
##
##infile = open ("DATA20.txt", "r")
##
##for i in range (10):
##    line = infile.readline ().strip ()
##    infile.readline ()
##
##    valid, a, b = is_valid (line, "0", "1")
##
##    if DEBUG:
##        print "valid, a, b =", valid, a, b
##    
##    if valid:
##        print get_string (get_binary (line, "0", "1"), a, b)
##    else:
##        valid, a, b = is_valid (line, "1", "0")
##
##        if DEBUG:
##            print "valid, a, b =", valid, a, b
##        
##        print get_string (get_binary (line, "1", "0"), a, b)
##    
##infile.close ()




def get_dec (bin):
    sum = 0
    for i in range (len (bin) - 1, -1, -1):
        sum += int (bin [i]) * (2 ** i)
    return sum


infile = open ("DATA21.txt", "r")

for i in range (10):
    line = infile.readline ().strip ()
    infile.readline ()

    is_first = True
    bin1 = ""
    bin2 = ""
    str1 = ""
    str2 = "" ; extras  = 0 ; lets = len(line) / 8 ; letters = 0

    for x in line:
        if x == "A" or x == "T":
            bin1 += "0"
            bin2 += "1"
        elif x == "C" or x == "G":
            bin1 += "1"
            bin2 += "0"

    while True:
        if get_dec (bin1 [0:8]) == 32 or 65 <= get_dec (bin1 [0:8]) <= 90:
            str1 += chr (get_dec (bin1 [0:8]) )
            bin1 = bin1 [8:]
            letters += 1
        else:
            bin1 = bin1 [1:]
            extras += 1

##            if extras == 7:
##                is_first = False
##                break

        if len (bin1) < 8:
            break

    if is_first == False:
        if get_dec (bin2 [0:8]) == 32 or 65 <= get_dec (bin2 [0:8]) <= 90:
            str2 += chr (get_dec (bin2 [0:8]) )
            bin2 = bin2 [8:]
            
        else:
            bin2 = bin2 [1:]

        if len (bin2) < 8:
            break

    if is_first:
        print str1
    else:
        print str2

infile.close()

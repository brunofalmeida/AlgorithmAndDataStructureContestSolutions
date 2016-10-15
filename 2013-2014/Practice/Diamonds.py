for z in range (5):
    word = raw_input ().strip ()

    print " " * (len (word) - 1) + word [0]
    for i in range (1, len (word)):
        print " " * (len (word) - i - 1) + word [i] + " " * (2 * i - 1) + word [i]

    for i in range (len (word) - 2, 0, -1):
        print " " * (len (word) - i - 1) + word [i] + " " * (2 * i - 1) + word [i]
    print " " * (len (word) - 1) + word [0]

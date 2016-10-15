N = int (raw_input ())
for i in range (1, N + 1):
    inp = raw_input ().strip ()
    M = int (inp [: inp.find (" ") ] )
    word = inp [inp.find (" ") + 1:]
    
    print i, word [:M - 1] + word [M:]

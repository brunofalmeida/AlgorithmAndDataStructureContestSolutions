T = raw_input ()
P = raw_input ()

i = T [::-1].find (P)
if i == -1:
    print -1
else:
    print len (T) - i

K = int (raw_input ())
oword = raw_input ()
nword = ""

for i, oletter in enumerate (list (oword)):
    S = 3 * (i + 1) + K
    nletter = chr (ord (oletter) - S)

    if (nletter < "a" and "a" <= oletter <= "z") or \
    (nletter < "A" and "A" <= oletter <= "Z"):
        nletter = chr (ord (nletter) + 26)

    nword += nletter

print nword

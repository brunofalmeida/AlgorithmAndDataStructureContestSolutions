for z in range (5):
    W = int (raw_input ())
    encoded = raw_input ()

    L = len (encoded) / W

    decoded = ""

    for a in range (L):
        for i in range (a, len (encoded), L):
            decoded += encoded [i]

    lines = []
    for i in range (L):
        lines.append (decoded [i * W : i * W + W])

    for i in range (L):
        while lines [i] [0] == " ":
            lines [i] = lines [i] [1: W]

    for l in lines [:-1]:
        print l,
    print lines [-1]

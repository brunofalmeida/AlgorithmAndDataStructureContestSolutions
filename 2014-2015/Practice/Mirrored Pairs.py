print "Ready"

while True:
    inp = raw_input().strip()
    
    if inp == "":
        break

    if inp in ["bd", "db", "pq", "qp"]:
        print "Mirrored pair"
    else:
        print "Ordinary pair"

N = int(raw_input())
s = bin(N)[bin(N).find("0b") + 2:]
print "1" * len(s)

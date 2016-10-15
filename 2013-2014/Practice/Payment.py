A = 0
B = 0
C = 0
D = 0
E = 0
F = 0

while True:
    int = input ()
    if int == -1:
        break
    elif int <= 9999:
        A += 1
    elif int <= 19999:
        B += 1
    elif int <= 29999:
        C += 1
    elif int <= 39999:
        D += 1
    elif int <= 49999:
        E += 1
    else:
        F += 1

print A
print B
print C
print D
print E
print F

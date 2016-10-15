N = int(raw_input())
for i in range(N):
    address = raw_input().strip()

    if (int(address[2], 16) % 2) == 1:
        print (address[0:2] + hex(int(address[2], 16) - 1)[2:3].upper() + address[3:8]),
    print address

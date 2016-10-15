m = int(raw_input().strip())
h1, a1 = map(int, raw_input().strip().split())
x1, y1 = map(int, raw_input().strip().split())
h2, a2 = map(int, raw_input().strip().split())
x2, y2 = map(int, raw_input().strip().split())

seconds = 0
height1 = h1
height2 = h2

while True:
    seconds += 1
    height1 = (x1 * height1 + y1) % m
    height2 = (x2 * height2 + y2) % m
    
    if height1 == a1 and height2 == a2:
        print seconds
        break

    elif height1 == h1 and height2 == h2:
        print -1
        break

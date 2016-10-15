# http://wcipeg.com/problem/ccc08s1


lowTemp = 999999
lowCity = ""

while True:
    line = raw_input().split()
    city = line[0]
    temp = int(line[1])
    
    if temp < lowTemp:
        lowTemp = temp
        lowCity = city
    
    if city == "Waterloo":
        break

print lowCity

def add (ottawa, hours, minutes):
    city = [ottawa [0] + hours, ottawa [1] + minutes]
    if city [1] >= 60:
        city [1] -= 60
        city [0] += 1
    if city [0] >= 24:
        city [0] -= 24
    return city

def subtract (ottawa, hours, minutes):
    city = [ottawa [0] - hours, ottawa [1] - minutes]
    if city [1] < 0:
        city [1] += 60
        city [0] -= 1
    if city [0] < 0:
        city [0] += 24
    return city

def string (city):
    str_city = ""
    if city [0] > 0:
        str_city += str (city [0])
    if city [1] < 10 and str_city != "":
        str_city += "0"
    str_city += str (city [1])
    return str_city

ottawa_temp = raw_input ()
if len (ottawa_temp) <= 2:
    ottawa = [0, int (ottawa_temp)]
else:
    ottawa = [int (ottawa_temp [:-2]), int (ottawa_temp [-2:])]

print ottawa_temp, "in Ottawa"
print string (subtract (ottawa, 3, 0)), "in Victoria"
print string (subtract (ottawa, 2, 0)), "in Edmonton"
print string (subtract (ottawa, 1, 0)), "in Winnipeg"
print ottawa_temp, "in Toronto"
print string (add (ottawa, 1, 0)), "in Halifax"
print string (add (ottawa, 1, 30)), "in St. John's"

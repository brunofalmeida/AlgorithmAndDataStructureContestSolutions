cities = {}

while True:
    string = raw_input ().split ()
    cities [string [0]] = int (string [1])
    if string [0] == "Waterloo":
        break

temperatures = cities.values ()
temperatures.sort ()
lowest_temp = temperatures [0]

for x in cities.keys ():
    if cities [x] == lowest_temp:
        print x

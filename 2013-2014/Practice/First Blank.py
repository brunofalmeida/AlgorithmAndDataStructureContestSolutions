counter = input ()

for x in range (counter):
    string = raw_input ()  
    index = string.find (" ")

    if index == -1:
        print 0
    else:
        print index + 1

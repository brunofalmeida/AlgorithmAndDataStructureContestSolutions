while True:
    exp = raw_input ().strip ().split ()

    if exp == ["0"]:
        break

    # single number
    if len (exp) == 1:
        print exp [0]

    for i in range (len (exp) ):
        # current item is an operator
        if not exp [i].isdigit ():
            # search until number of numbers == number of operators + 1
            count_n = 0
            count_o = 1
            i2 = i + 1
            while True:
                if exp [i2].isdigit ():
                    count_n += 1
                else:
                    count_o += 1

                if count_n = count_o + 1:
                    break
                
                i2 += 1

    exp.insert (index, object)

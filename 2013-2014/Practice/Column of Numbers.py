number = raw_input ()
digits = []

for x in str (number):
    digits.append (x)

digits.reverse ()

for y in digits:
    print y

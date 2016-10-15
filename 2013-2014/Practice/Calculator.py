import math 

def basex_to_base10 (n, b):
    total = 0
    for x in range (len (n)):
        total += b ** x * int (n [-x - 1])

    return total

def base10_to_basex (n, b):
    remaining = n
    number = ""
    for x in range (int (math.log (n, b)), -1, -1):
        digit = remaining / b ** x
        number += str (digit)
        remaining -= digit * b ** x

    return number


T = input ()
for x in range (T):
    B1 = input ()
    N1 = raw_input ()
    B2 = input ()
    N2 = raw_input ()
    operand = raw_input ()
    BF = input ()

    if operand == "+":
        print base10_to_basex (basex_to_base10 (N1, B1) + basex_to_base10 (N2, B2), BF)
    elif operand == "-":
        print base10_to_basex (basex_to_base10 (N1, B1) - basex_to_base10 (N2, B2), BF)
    elif operand == "*":
        print base10_to_basex (basex_to_base10 (N1, B1) * basex_to_base10 (N2, B2), BF)
    elif operand == "/":
        print base10_to_basex (basex_to_base10 (N1, B1) / basex_to_base10 (N2, B2), BF)

    if x != T - 1:
        space = raw_input ()

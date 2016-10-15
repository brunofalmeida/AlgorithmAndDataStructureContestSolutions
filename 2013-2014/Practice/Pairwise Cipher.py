for z in range (5):
    key_phrase = raw_input ()
    encoded_message = raw_input ()

    scrambled_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    # Line up letters of key together with the alphabet
    for c in encoded_message:
        if c != " ":
            scrambled_alphabet = c.upper () + scrambled_alphabet

    # Check for and delete repeat letters
    while True:
        delete = []
        for i in range (len (scrambled_alphabet) ):
            if scrambled_alphabet [i] in scrambled_alphabet [:i]:
                delete.append (i)

        if delete == []:
            break
        for i in delete [::-1]:
            del scrambled_alphabet [i]

    pairs = [[] for i in range (len (encoded_message) / 2 + len (encoded_message) % 2)]
    for i, x in enumerate (encoded_message):
        pairs [i / 2].append (x)

    # index % len (alphabet)

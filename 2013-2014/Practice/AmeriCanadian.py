while True:
    word = raw_input ().strip ()
    if word == "quit!":
        break

    if len (word) > 4 and word.endswith ("or") and word [-3] not in "aeiouy":
        print word [: -2] + "our"
    else:
        print word

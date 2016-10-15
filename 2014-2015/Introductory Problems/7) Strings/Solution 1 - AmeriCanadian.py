while True:
    word = raw_input()

    if word == "quit!":
        break

    if len(word) > 4 and word[-3] not in "aeiouy" and word[-2:] == "or":
        # replaces occurences of "or" in word with "our"
        print word.replace("or", "our")
    else:
        print word

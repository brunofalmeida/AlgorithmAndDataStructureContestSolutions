# Make the while condition always True
# (Keep looping until we break from inside the loop)
while True:

    # Input the word as a string
    word = raw_input()

    # Check if the word is "quit!" - break out of the while loop if it is
    # ("quit!" is spelled exactly as stated in the problem -
    #  lowercase letters, exclamation point)
    if word == "quit!":
        break


    # Check the 3 conditions for American spelling
    # Uses 'and' to combine expressions - all conditions must be True to execute

    # 1. Get the length of the word and check if it's more than 4
    
    # 2. Get the third last letter
    #    (word[-1] gets the last letter, so word[-3] gets the third last letter)
    
    #    Then, check if the letter is a consonant
    #    (is not found in a string containing all possible vowels)

    # 3. Check if the word ends with "or"
    #    (The endswith() function will return True if the word ends with "or")
    
    if (len(word) > 4) and (word[-3] not in "aeiouy") and (word.endswith("or")):
        
        # If all the conditions are True, this will run
        # Print the word and replace "or" with "our"
        
        # The replace() function will return a new string,
        # replacing occurences of "or" with "our"
        print word.replace("or", "our")

        
    else:

        # If any of the conditions are False, this will run
        # Print the word as it is
        print word

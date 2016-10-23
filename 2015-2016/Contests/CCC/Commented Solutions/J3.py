# Function version 1: iteration
# Returns True if the word is a palindrome, or False if it isn't
def isPalindrome1(word):

    # Check each pair of letters until the middle of the string
    for i in range(len(word) / 2):
        # Check if the letter at index i from the beginning
        # equals the letter at index i from the end
        if word[i] != word[len(word) - 1 - i]:
            # If they aren't equal, the word is not a palindrome
            return False

    # If we made it through all the letters without returning False,
    # the word must be a palindrome
    return True


# Function version 2: recursion
# Returns True if the word is a palindrome, or False if it isn't
def isPalindrome2(word):

    # If the word has 0 or 1 letters
    if len(word) == 0 or len(word) == 1:
        return True

    # If the first and last letters aren't equal
    elif word[0] != word[-1]:
        return False

    # The first and last letters are equal, so keep recursing
    else:
        return isPalindrome2( word[1 : len(word) - 1] )




word = raw_input()
longestPalindrome = ""

# Loop through all possible lengths of substrings in the word
for length in range(1, len(word) + 1):
    # Given a substring length, loop through all possible starting indices
    for startIndex in range(0, len(word) - length + 1):
        # Get the substring with the given starting index and length
        substring = word[startIndex : startIndex + length]

        # If the substring is a palindrome and longer than the stored palindrome,
        # make it the new stored palindrome
        if isPalindrome1(substring) and len(substring) > len(longestPalindrome):
            longestPalindrome = substring


print len(longestPalindrome)

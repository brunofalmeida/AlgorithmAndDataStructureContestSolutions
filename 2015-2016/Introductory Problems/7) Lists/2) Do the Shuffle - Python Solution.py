# Create the playlist (a list of strings)
plist = ["A", "B", "C", "D", "E"]


# Keep looping - make the condition always True
# The program will break out of the loop from inside it
while True:
    
    # Input the two numbers: b (button) and n (number of times to press)
    b = int( raw_input() )
    n = int( raw_input() )

    # If b is 4 and n is 1,
    # stop rearranging songs and break out of the while loop
    if b == 4 and n == 1:
        break

    # Loop n times (the button is pressed n times)
    for i in range(n):
        
        # Make a copy of the playlist to preserve its old state       
        # The [:] is a splice - copies all the elements in the list
        # If you don't use [:], changes to plist will also affect plistOld
        plistOld = plist[:]

        # Check the button number and perform the appropriate action

        # Button 1 - move the first song to the end
        if b == 1:

            # The numbers in square brackets [] access an index in the list
            # Remember: the first index is always 0!
            # e.g. plist[0] is the first item in plist, plist[1] is the second
            
            plist[0] = plistOld[1]
            plist[1] = plistOld[2]
            plist[2] = plistOld[3]
            plist[3] = plistOld[4]
            plist[4] = plistOld[0]
                                            
        # Button 2 - move the last song to the start
        elif b == 2:
            plist[0] = plistOld[4]
            plist[1] = plistOld[0]
            plist[2] = plistOld[1]
            plist[3] = plistOld[2]
            plist[4] = plistOld[3]
            
        # Button 3 - swap the first two songs
        elif b == 3:
            plist[0] = plistOld[1]
            plist[1] = plistOld[0]


# After breaking out of the loop, print the final playlist

# Loop through each element in the list
# (Each time through the loop, song becomes the next item in the list)
for song in plist:

    # Print the song
    # The comma adds a space and keeps the next print operation on the same line
    # (The next time print is called, it will be on the same line as this one)
    print song,

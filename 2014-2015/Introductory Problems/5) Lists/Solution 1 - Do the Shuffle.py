plist = ["A", "B", "C", "D", "E"]

while True:
    b = int( raw_input() )
    n = int( raw_input() )

    if b == 1:  # move the first song of the playlist to the end of the playlist
        i = 0
        while i < n:
            plist_old = plist[:]    # plist[:] makes a copy of plist
                                    # copy preserves playlist before rearrangement
            plist[4] = plist_old[0]     # take first song of old playlist and
                                        # make it last song of new playlist
            plist[0:4] = plist_old[1:5]     # take last 4 songs of old playlist and
                                            # make them first 4 songs of new playlist
            i += 1

    elif b == 2:  # move the last song of the playlist to the start of the playlist
        i = 0
        while i < n:
            plist_old = plist[:]
            
            plist[0] = plist_old[4]     # take last song of old playlist and
                                        # make it first song of new playlist
            plist[1:5] = plist_old[0:4]     # take first 4 songs of old playlist and
                                            # make them last 4 songs of new playlist
            i += 1

    elif b == 3:  # swap the first two songs of the playlist
        i = 0
        while i < n:
            plist_old = plist[:]
            
            plist[0] = plist_old[1]     # take second song of old playlist and
                                        # make it first song of new playlist
            plist[1] = plist_old[0]     # take first song of old playlist and
                                        # make it second song of new playlist
            i += 1

    elif b == 4 and n == 1:   # stop rearranging songs and output the playlist
        i = 0
        while i < 4:    # print each song (except the last one) with a space
            print plist[i],
            i += 1
        print plist[4]     # print last song without a space
            
        break

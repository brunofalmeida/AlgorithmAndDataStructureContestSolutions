import copy

def len_words (words):
    counter = 0
    for x in words:
        counter += len (x)
    return counter

w = int (raw_input ())
words = ["WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"]

wordsLines = [[]]
for i, x in enumerate (words):     # len (words)
    wordsLine_test = copy.deepcopy (wordsLines [-1])
    wordsLine_test.append (x)
    if len_words (wordsLine_test) + len (wordsLine_test) - 1 <= w:
        wordsLines [-1].append (x)
    else:
        wordsLines.append ([x])

spacesLines = []
for x in wordsLines:
    if len (x) == 1:
        spaces = ["." * (w - len (x [0]))]
        
    else:
        num_spaces = w - len_words (x)
        min_spaces = num_spaces / (len (x) - 1)
        extra_spaces = num_spaces % (len (x) - 1)
        
        spaces = ["." * min_spaces] * (len (x) - 1)
        for i in range (extra_spaces):
            spaces [i] += "."

    spacesLines.append (spaces)

for i in range (len (wordsLines)):
    line = ""
    if len (wordsLines [i]) == 1:
        line += wordsLines [i] [0] + spacesLines [i] [0]
    
    else:
        for j in range (len (wordsLines [i]) - 1):
            line += wordsLines [i] [j] + spacesLines [i] [j]
        line += wordsLines [i] [-1]
        
    print line

def distance (c1,c2):
    global grid
    return abs (grid [c1] [0] - grid [c2] [0]) + abs (grid [c1] [1] - grid [c2] [1])

grid = {}
grid ["A"] = [1, 1]
grid ["B"] = [2, 1]
grid ["C"] = [3, 1]
grid ["D"] = [4, 1]
grid ["E"] = [5, 1]
grid ["F"] = [6, 1]
grid ["G"] = [1, 2]
grid ["H"] = [2, 2]
grid ["I"] = [3, 2]
grid ["J"] = [4, 2]
grid ["K"] = [5, 2]
grid ["L"] = [6, 2]
grid ["M"] = [1, 3]
grid ["N"] = [2, 3]
grid ["O"] = [3, 3]
grid ["P"] = [4, 3]
grid ["Q"] = [5, 3]
grid ["R"] = [6, 3]
grid ["S"] = [1, 4]
grid ["T"] = [2, 4]
grid ["U"] = [3, 4]
grid ["V"] = [4, 4]
grid ["W"] = [5, 4]
grid ["X"] = [6, 4]
grid ["Y"] = [1, 5]
grid ["Z"] = [2, 5]
grid [" "] = [3, 5]
grid ["-"] = [4, 5]
grid ["."] = [5, 5]
grid ["\n"] = [6, 5]


phrase = raw_input ()
counter = 0

counter += distance ("A", phrase [0] )
for i in range (len (phrase) - 1):
    counter += distance (phrase [i], phrase [i + 1] )
counter += distance (phrase [-1], "\n")

print counter

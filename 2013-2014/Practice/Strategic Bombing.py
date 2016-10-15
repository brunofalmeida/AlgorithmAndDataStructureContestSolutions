graph = {}
E = []

# Construct graph (list and set of points) from input
while True:
    inp = raw_input ().strip ()
    if inp == "**":
        break

    if inp [0] not in graph.keys ():
        graph [inp [0]] = []
    if inp [1] not in graph.keys ():
        graph [inp [1]] = []

    graph [inp [0]].append (inp [1])
    graph [inp [1]].append (inp [0])
    E.append ( (inp [0], inp [1]) )




counter = 0
d_roads = []
# Check each road that can be bombed
for road in E:
    # Remove road from graph
    graph [road [0]].remove (road [1])
    graph [road [1]].remove (road [0])

    # Check if destination can be reached (DFS)
    is_disconnecting = True
    visited = set ()
    stack = ["A"]
    
    while len (stack) > 0:
        point = stack.pop ()
        
        if point == "B":
            is_disconnecting = False
            break

        for p in graph [point]:
            if p not in visited:
                stack.append (p)

        visited.add (point)
            

    counter += int (is_disconnecting)
    if is_disconnecting:
        d_roads.append (road)


    # Readd road to graph
    graph [road [0]].append (road [1])
    graph [road [1]].append (road [0])




for r in d_roads:
    print r [0] + r [1]
print "There are", counter, "disconnecting roads."

from collections import deque

W = int (raw_input ())
cars = deque ()
for i in range (int (raw_input ())):
    cars.append (int (raw_input ()))

counter = 0
total = 0
bridge = deque ()
while len (cars) > 0:
    if len (bridge) == 4:
        total -= bridge [0]
        bridge.popleft ()
        
    bridge.append (cars.popleft ())
    total += bridge [-1]

    if total > W:
        break

    counter += 1

print counter

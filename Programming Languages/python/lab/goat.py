#!/usr/bin/env python3


from collections import deque

# Define the initial and forbidden states
init = frozenset({'man', 'wolf', 'goat', 'cabbage'}), frozenset()
forbidden = [frozenset({'wolf', 'goat'}), frozenset({'goat', 'cabbage'})]

# Function to generate next possible states
def next(s):
    # Determine the side the man is currently on
    edge = 0 if "man" in s[0] else 1
    # Iterate over items that can be moved
    for x in s[edge]:
        # Compute the source and target states after moving the item
        source = s[edge] - frozenset({"man", x})
        target = s[1-edge] | frozenset({"man", x})
        # Check if the move violates any forbidden states
        if any(bad <= source for bad in forbidden):
            continue
        # Yield the valid move
        yield (source, target) if edge == 0 else (target, source)

# Breadth-first search solver
Q = deque([init])
prev = {init: None}
solved = False
while Q:
    s = Q.popleft()
    if not s[0]:
        solved = True
        break
    for t in next(s):
        if t not in prev:
            Q.append(t)
            prev[t] = s

# If a solution is found, print the path
if solved:
    # Trace back the path and print each state
    path = []
    while s:
        path.append(s)
        s = prev[s]
    # Reverse the final list as requested
    path.reverse()
    for state in path:
        print("West:", ", ".join(state[0]) if state[0] else "Nothing")
        print("East:", ", ".join(state[1]) if state[1] else "Nothing")
        print()  # Add an empty line for readability between states


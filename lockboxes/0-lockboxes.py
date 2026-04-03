#!/usr/bin/python3
"""Module for checking if all boxes can be opened"""
from collections import deque

def canUnlockAll(boxes):
    """main function to check if the boxes can be opened"""
    visited = set([0])
    queue = deque([0])

    while queue:
        box = queue.popleft()

        for key in boxes[box]:
            if key not in visited and key < len(boxes):
                visited.add(key)
                queue.append(key)

    return len(visited) == len(boxes)

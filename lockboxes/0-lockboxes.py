from collections import deque

def canUnlockAll(boxes):
    visited = set([0])
    queue = deque([0])

    while queue:
        box = queue.popleft()

        for key in boxes[box]:
            if key not in visited:
                visited.add(key)
                queue.append(key)

    return len(visited) == len(boxes)

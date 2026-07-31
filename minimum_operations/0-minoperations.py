#!/usr/bin/python3
"""
Function to calculate the minimum number of operations
to reach a given number of characters
"""


def minOperations(n):
    """
    Calculate the minimum number of operations to reach n characters
    using only copy and paste operations.

    Args:
        n (int): The target number of characters.
    """
    if n < 2:
        return 0

    result = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            result += divisor
            n //= divisor
        divisor += 1

    return result

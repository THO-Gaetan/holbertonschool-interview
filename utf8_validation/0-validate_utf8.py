#!/usr/bin/python3
"""
Validates if a given data set represents a valid UTF-8 encoding.
"""
def validUTF8(data):
    """
    Validates if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes.

    Returns:
        bool: True if the data is a valid UTF-8 encoding, False otherwise.
    """
    # Implementation for validating UTF-8 encoding
    i = 0
    while i < len(data):
        byte = data[i] & 0xFF

        if byte >> 7 == 0:
            # 1-byte character (0xxxxxxx)
            i += 1
        elif byte >> 5 == 0b110:
            # 2-byte character (110xxxxx 10xxxxxx)
            if i + 1 >= len(data) or (data[i + 1] & 0xFF) >> 6 != 0b10:
                return False
            i += 2
        elif byte >> 4 == 0b1110:
            # 3-byte character (1110xxxx 10xxxxxx 10xxxxxx)
            if (i + 2 >= len(data) or
                    (data[i + 1] & 0xFF) >> 6 != 0b10 or
                    (data[i + 2] & 0xFF) >> 6 != 0b10):
                return False
            i += 3
        elif byte >> 3 == 0b11110:
            # 4-byte character (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
            if (i + 3 >= len(data) or
                    (data[i + 1] & 0xFF) >> 6 != 0b10 or
                    (data[i + 2] & 0xFF) >> 6 != 0b10 or
                    (data[i + 3] & 0xFF) >> 6 != 0b10):
                return False
            i += 4
        else:
            return False
    return True

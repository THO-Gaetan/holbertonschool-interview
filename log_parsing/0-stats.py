#!/usr/bin/python3
"""Reads stdin line by line and computes HTTP log metrics."""
import sys
if __name__ == "__main__":
    st_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    count = 1
    file_size = 0

    def parse_line(line):
        """Parses a line of input and updates the metrics."""
        global file_size
        global st_code
        try:
            parts = line.split()
            file_size += int(parts[-1])
            status_code = parts[-2]
            if status_code in st_code:
                st_code[status_code] += 1
        except (IndexError, ValueError):
            pass

    def print_metrics():
        """Prints the current metrics."""
        print("File size: {}".format(file_size))
        for code in sorted(st_code.keys()):
            if st_code[code] > 0:
                print("{}: {}".format(code, st_code[code]))

    for line in sys.stdin:
        parse_line(line)
        if count % 10 == 0:
            print_metrics()
        count += 1
    


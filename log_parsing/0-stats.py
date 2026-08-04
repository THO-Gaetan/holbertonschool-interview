#!/usr/bin/python3
"""Reads stdin line by line and computes HTTP log metrics."""
import sys

STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]


def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for code in STATUS_CODES:
        if status_counts.get(code):
            print("{}: {}".format(code, status_counts[code]))


def run():
    total_size = 0
    status_counts = {}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()

            if len(parts) < 2:
                continue

            status_code, file_size = parts[-2], parts[-1]

            try:
                file_size = int(file_size)
            except ValueError:
                continue

            try:
                status_code = int(status_code)
            except ValueError:
                continue

            total_size += file_size
            if status_code in STATUS_CODES:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
    else:
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    run()
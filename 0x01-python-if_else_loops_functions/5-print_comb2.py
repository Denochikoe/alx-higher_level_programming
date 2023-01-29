#!/usr/bin/python3
for a in range(0, 100):
    print("{:d}, ".format(a), end='')
    if a == 99:
        print('{:d}'.format(a))

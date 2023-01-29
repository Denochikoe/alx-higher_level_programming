#!/usr/bin/python3
for a in range(0, 100):
    print("{:02}, ".format(a), end='')
    if a == 99:
        print('{:02}'.format(a))

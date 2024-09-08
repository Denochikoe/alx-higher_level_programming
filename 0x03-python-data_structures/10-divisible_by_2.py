#!/usr/bin/python3


def divisible_by_2(my_list=[]):
    result = [number % 2 == 0 for number in my_list]   
    return result

#!/usr/bin/python3


def no_c(my_string):
    # Initialize an empty string to store the result
    new_string = ""
    
    # Iterate over each character in the input string
    for char in my_string:
        # Add characters to the new string only if they are not 'c' or 'C'
        if char != 'c' and char != 'C':
            new_string += char
    
    # Return the modified string without 'c' or 'C'
    return new_string

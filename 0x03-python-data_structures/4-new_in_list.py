#!/usr/bin/python3


def new_in_list(my_list, idx, element):
    # Create a copy of the original list
    new_list = my_list[:]
    # Check if the index is within the valid range
    if idx < 0 or idx >= len(my_list):
        # Return the copied list if index is invalid
        return new_list
    # Replace the element at the specified index in the new list
    new_list[idx] = element
    # Return the modified copy of the list
    return new_list

#!/usr/bin/python3


def replace_in_list(my_list, idx, element):
    # Check if the index is within the valid range
    if idx < 0 or idx >= len(my_list):
        # Return the original list if index is invalid
        return my_list

    # Replace the element at the specified index
    my_list[idx] = element
    # Return the modified list
    return my_list

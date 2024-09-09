#!/usr/bin/python3


def complex_delete(a_dictionary, value):
    # Create a list of keys to delete
    keys_to_delete = [key for key, val in a_dictionary.items() if val == value]
    # Remove the keys from the dictionary
    for key in keys_to_delete:
        del a_dictionary[key]
    # Return the modified dictionary
    return a_dictionary

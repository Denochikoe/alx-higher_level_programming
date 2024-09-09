#!/usr/bin/python3


def complex_delete(a_dictionary, value):
    """
    Deletes all keys in a dictionary that have the specified value and returns the updated dictionary.

    Args:
        a_dictionary (dict): The dictionary to modify.
        value: The value to search for and delete keys with.

    Returns:
        dict: The modified dictionary after deleting the specified keys.
    """
    # Create a list of keys to delete
    keys_to_delete = [key for key, val in a_dictionary.items() if val == value]

    # Remove the keys from the dictionary
    for key in keys_to_delete:
        del a_dictionary[key]
    
    # Return the modified dictionary
    return a_dictionary

#!/usr/bin/python3


def print_matrix_integer(matrix=[[]]):
    # Iterate through each row in the matrix
    for row in matrix:
        # Initialize an empty list to hold formatted string of row elements
        formatted_row = []

        # Iterate through each element in the row
        for element in row:
            formatted_row.append("{:d}".format(element))

        # Join the formatted elements with a space and print the row
        print(" ".join(formatted_row))

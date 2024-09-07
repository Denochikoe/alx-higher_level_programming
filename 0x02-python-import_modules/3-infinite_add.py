#!/usr/bin/python3
import sys


def main():
    args = sys.argv[1:]
    
    # Convert arguments to integers and sum them up
    total = sum(int(arg) for arg in args) 
    # Print the result
    print(total)


# Ensure the code only runs when executed directly
if __name__ == "__main__":
    main()

#!/usr/bin/python3
import importlib.util
import inspect

def main():
    # Load the compiled module hidden_4.pyc
    module_name = "hidden_4"
    module_path = "./hidden_4.pyc"  # Adjust the path if necessary

    # Load the module from the compiled file
    spec = importlib.util.spec_from_file_location(module_name, module_path)
    hidden_module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(hidden_module)

    # Get all names defined in the module
    names = dir(hidden_module)

    # Filter names that do not start with '__' and sort them alphabetically
    filtered_names = sorted(name for name in names if not name.startswith("__"))

    # Print each name on a new line
    for name in filtered_names:
        print(name)

# Ensure the code only runs when executed directly
if __name__ == "__main__":
    main()

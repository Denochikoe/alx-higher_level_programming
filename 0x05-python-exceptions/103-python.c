#include <Python.h>
#include <stdio.h>

// Function to print information about a Python list
void print_python_list(PyObject *p) {
    Py_ssize_t size, allocated, i;
    PyObject *item;

    // Check if the object is a valid Python list
    if (!PyList_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    // Manually access the size and allocated space of the list
    size = ((PyVarObject *)p)->ob_size;  // Equivalent to PyList_Size(p)
    allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    // Iterate through the list and print the type of each element
    for (i = 0; i < size; i++) {
        item = ((PyListObject *)p)->ob_item[i];  // Access the list elements directly
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);  // Print the type of each element
    }
}

// Function to print information about a Python bytes object
void print_python_bytes(PyObject *p) {
    Py_ssize_t size;
    char *string;
    Py_ssize_t i, limit;

    // Check if the object is a valid Python bytes object
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;  // Access the size of the bytes object
    string = ((PyBytesObject *)p)->ob_sval;  // Access the raw byte string

    printf("[*] Python bytes info\n");
    printf("[*] Size: %zd\n", size);
    printf("[*] Trying string: %s\n", string);

    // Print the first 10 bytes in hexadecimal format
    limit = size < 10 ? size + 1 : 10;
    printf("[*] First %zd bytes: ", limit);
    for (i = 0; i < limit; i++) {
        printf("%02x ", (unsigned char)string[i]);
    }
    printf("\n");
}

// Function to print information about a Python float object
void print_python_float(PyObject *p) {
    double value;

    // Check if the object is a valid Python float object
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    value = ((PyFloatObject *)p)->ob_fval;  // Access the float value directly
    printf("[*] Python float info\n");
    printf("[*] Value: %f\n", value);
}

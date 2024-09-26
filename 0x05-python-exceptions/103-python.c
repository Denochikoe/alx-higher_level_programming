#include <stdio.h>
#include <Python.h>  // Ensure you have Python.h included

void print_python_float(PyObject *p);
void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

void print_python_float(PyObject *p) {
    if (PyFloat_Check(p)) {
        double value = PyFloat_AsDouble(p);
        printf("[.] float object info\n");
        printf("  value: %.12g\n", value);  // Print float with precision
    } else {
        printf("[ERROR] Invalid Float Object\n");
    }
}

void print_python_list(PyObject *p) {
    if (PyList_Check(p)) {
        Py_ssize_t size = PyList_Size(p);
        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", size);  // Assuming allocated is equal to size

        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *item = PyList_GetItem(p, i);
            if (PyFloat_Check(item)) {
                printf("Element %zd: float\n", i);
                print_python_float(item);  // Call the function to print each float
            } else if (PyBytes_Check(item)) {
                printf("Element %zd: bytes\n", i);
                print_python_bytes(item);  // Call function to print bytes
            } else {
                printf("Element %zd: [ERROR] Invalid Type\n", i);
            }
        }
    } else {
        printf("[ERROR] Invalid List Object\n");
    }
}

void print_python_bytes(PyObject *p) {
    if (PyBytes_Check(p)) {
        Py_ssize_t size = PyBytes_Size(p);
        printf("[.] bytes object info\n");
        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", PyBytes_AsString(p));

        printf("  first %zd bytes:", size < 10 ? size : 10);
        for (Py_ssize_t i = 0; i < (size < 10 ? size : 10); i++) {
            printf(" %02x", (unsigned char)PyBytes_AsString(p)[i]);
        }
        printf("\n");
    } else {
        printf("[ERROR] Invalid Bytes Object\n");
    }
}

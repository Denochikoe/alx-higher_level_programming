#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

void print_python_list(PyObject *p)
{
    Py_ssize_t size, allocated, i;
    PyObject *item;

    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size; // Size of the list
    allocated = ((PyListObject *)p)->allocated; // Allocated size

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i); // Get the item safely
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name); // Get the type name

        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
        else
            printf("Element %zd: [ERROR] Unsupported type\n", i);
    }
}

void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p); // Get size of the bytes object
    str = PyBytes_AsString(p); // Get the string representation

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str ? str : "(null)");

    printf("  first %zd bytes:", size > 10 ? 10 : size);
    for (i = 0; i < (size > 10 ? 10 : size); i++)
    {
        printf(" %02x", (unsigned char)str[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p)
{
    double value;

    printf("[.] float object info\n");

    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = PyFloat_AsDouble(p); // Get the double value from the float object
    printf("  value: %.12g\n", value); // Print with precision
}


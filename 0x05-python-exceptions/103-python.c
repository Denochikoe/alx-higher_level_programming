#include <stdio.h>
#include <Python.h>

void print_python_list(PyObject *p)
{
    Py_ssize_t i, size;
    PyObject *item;

    if (!PyList_Check(p)) {
        printf("[ERROR] Invalid List Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++) {
        item = ((PyListObject *)p)->ob_item[i];
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
    }
}


void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("Invalid PyBytesObject\n");
        return;
    }

    Py_ssize_t size = 0;
    const char *bytes_str = PyBytes_AsString(p);
    for (size = 0; bytes_str[size] != '\0'; size++);

    printf("[*] Python bytes info\n");
    printf("[*] Size of the Python Bytes = %zd\n", size);

    printf("[*] First %zd bytes: ", (size > 10) ? 10 : size);
    for (Py_ssize_t i = 0; i < ((size > 10) ? 10 : size); i++) {
        printf("%02x ", (unsigned char)bytes_str[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p)) {
        printf("Invalid PyFloatObject\n");
        return;
    }

    double value = PyFloat_AsDouble(p);
    printf("[*] Python float info\n");
    printf("[*] Value of the float = %.10f\n", value);
}

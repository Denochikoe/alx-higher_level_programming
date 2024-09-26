#include <stdio.h>
#include <Python.h>

void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    if (!PyList_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
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
    Py_ssize_t size;
    char *string;

    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    string = ((PyBytesObject *)p)->ob_sval;

    printf("[*] Python bytes info\n");
    printf("[*] Size: %zd\n", size);
    printf("[*] Trying string: %s\n", string);
    printf("[*] First %zd bytes: ", size < 10 ? size + 1 : 10);
	for (Py_ssize_t i = 0; i < size && i < 10; i++)
	{
        printf("%02x ", (unsigned char)string[i]);
	}
    printf("\n");
}

void print_python_float(PyObject *p) {
    double value;

    if (!PyFloat_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    value = ((PyFloatObject *)p)->ob_fval;
    printf("[*] Python float info\n");
    printf("[*] Value: %f\n", value);
}

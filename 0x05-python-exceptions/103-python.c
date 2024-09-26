#include <Python.h>
#include <stdio.h>

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: PyObject (expected to be a bytes object)
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;
    PyBytesObject *bytes;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;
    size = ((PyVarObject *)p)->ob_size;
    str = bytes->ob_sval;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str);

    printf("  first %zd bytes:", size >= 10 ? 10 : size + 1);
    for (i = 0; i < size && i < 10; i++)
    {
        printf(" %02x", (unsigned char)str[i]);
    }

    if (size < 10)
    {
        printf(" 00");
    }

    printf("\n");
}

/**
 * print_python_float - Prints information about a Python float object
 * @p: PyObject (expected to be a float object)
 */
void print_python_float(PyObject *p)
{
    double value;

    printf("[.] float object info\n");

    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = ((PyFloatObject *)p)->ob_fval;

    /* Printing with maximum precision using %.16g to meet expected output */
    printf("  value: %.15g\n", value); 
}

/**
 * print_python_list - Prints information about a Python list object
 * @p: PyObject (expected to be a list object)
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;
    PyListObject *list;

    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    list = (PyListObject *)p;
    
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        item = list->ob_item[i];
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);

        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
        else
            printf("  [ERROR] Unsupported type\n");
    }
}

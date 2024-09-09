#include <Python.h>
#include <stdio.h>

/* Function prototypes */
void print_python_bytes(PyObject *p);
void print_python_list(PyObject *p);

/**
 * print_python_list - Prints basic information about a Python list.
 * @p: A pointer to the Python object (list) to be printed.
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t i, size;
    PyObject *item;

    if (!PyList_Check(p))
    {
        printf("[ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item))
        {
            print_python_bytes(item);
        }
    }
}

/**
 * print_python_bytes - Prints basic information about a Python bytes object.
 * @p: A pointer to the Python object (bytes) to be printed.
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;

    if (!PyBytes_Check(p))
    {
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", (size < 10) ? str : "Error: String too long");

    printf("  first %zd bytes: ", (size < 10) ? size : 10);
    for (i = 0; i < ((size < 10) ? size : 10); i++)
    {
        printf("%02x ", (unsigned char)str[i]);
    }
    printf("\n");
}

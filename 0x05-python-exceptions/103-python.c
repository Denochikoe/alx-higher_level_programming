#include <Python.h>
#include <stdio.h>

/* Function prototypes */
void print_python_bytes(PyObject *p);
void print_python_list(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: PyObject (expected to be a bytes object)
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    const char *str;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str ? str : "(null)");

    printf("  first %zd bytes: ", size < 10 ? size : 10);
    for (i = 0; i < size && i < 10; i++)
    {
        printf("%02x ", (unsigned char)str[i]);
    }
    if (size < 10)
        printf("\n");
    else
        printf("%02x\n", (unsigned char)str[i-1]);

    if (size < 10)
    {
        for (; i < 10; i++)
        {
            printf("00 ");
        }
        printf("\n");
    }
}

/**
 * print_python_list - Prints information about a Python list object
 * @p: PyObject (expected to be a list object)
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GET_ITEM(p, i);
        printf("Element %zd: ", i);

        if (PyFloat_Check(item))
        {
            printf("float\n");
            print_python_float(item);
        }
        else
        {
            printf("[ERROR] Invalid Item Type\n");
        }
    }
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

    value = PyFloat_AsDouble(p);

    if ((long)value == value)
    {
        printf("  value: %.1f\n", value);
    }
    else
    {
        printf("  value: %.15g\n", value);
    }
}

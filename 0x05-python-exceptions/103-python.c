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

    /* Check if the object is a valid bytes object */
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    /* Cast PyObject to PyBytesObject to access byte array */
    bytes = (PyBytesObject *)p;

    /* Get the size of the byte string */
    size = ((PyVarObject *)p)->ob_size;

    /* Get the pointer to the byte array */
    str = bytes->ob_sval;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str);

    /* Print the first 10 bytes or fewer */
    printf("  first %zd bytes:", size >= 10 ? 10 : size);

    /* Print up to the first 9 bytes if available */
    for (i = 0; i < size && i < 10; i++)
    {
        printf(" %02x", (unsigned char)str[i]);
    }

    /* If there are fewer than 10 bytes, print an extra null byte (0x00) */
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

    /* Check if the object is a valid float object */
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    /* Get the value of the float */
    value = ((PyFloatObject *)p)->ob_fval;

    /* Print the float value with appropriate formatting */
    if (value == (int)value)
        printf("  value: %.1f\n", value);  /* Ensure decimal point for integer-like floats */
    else
        printf("  value: %.16g\n", value); /* Use up to 16 significant digits for non-integer floats */
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

    /* Check if the object is a valid list object */
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    /* Get the size of the list */
    size = ((PyVarObject *)p)->ob_size;

    /* Get the allocated size of the list */
    list = (PyListObject *)p;
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", list->allocated);

    /* Iterate through the list and print type information */
    for (i = 0; i < size; i++)
    {
        item = list->ob_item[i];
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);

        /* Call appropriate function for specific types */
        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
        else
            printf("  [ERROR] Unsupported type\n"); // Handle unsupported types
    }
}

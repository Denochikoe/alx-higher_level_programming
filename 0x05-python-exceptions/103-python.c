#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/* Access PyListObject directly to get size and items */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, allocated, i;
    PyObject **items;
    PyListObject *list;

    printf("[*] Python list info\n");

    /* Check if p is a list object */
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;  /* Cast to access PyListObject fields */
    size = ((PyVarObject *)p)->ob_size;  /* Manually get list size */
    allocated = list->allocated;  /* Access allocated field */
    items = list->ob_item;  /* Access list elements */

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (i = 0; i < size; i++)
    {
        PyObject *item = items[i];  /* Directly access list item */
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);

        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
    }
}

/* Access PyBytesObject directly to print the bytes */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;
    PyBytesObject *bytes;

    printf("[.] bytes object info\n");

    /* Check if p is a bytes object */
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;  /* Cast to access PyBytesObject fields */
    size = ((PyVarObject *)p)->ob_size;  /* Manually get size */
    str = bytes->ob_sval;  /* Access byte array directly */

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str);

    /* Print the first 10 bytes or fewer */
    printf("  first %zd bytes:", size > 10 ? 10 : size);
    for (i = 0; i < (size > 10 ? 10 : size); i++)
    {
        printf(" %02x", (unsigned char)str[i]);
    }
    printf("\n");
}

/* Access PyFloatObject directly to print the float */
void print_python_float(PyObject *p)
{
    double value;
    PyFloatObject *float_obj;

    printf("[.] float object info\n");

    /* Check if p is a float object */
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    float_obj = (PyFloatObject *)p;  /* Cast to access PyFloatObject fields */
    value = float_obj->ob_fval;  /* Access the float value */

    printf("  value: %.16g\n", value);
}

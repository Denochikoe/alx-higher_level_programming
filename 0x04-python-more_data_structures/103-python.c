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
    PyListObject *list_object;

    /* Verify if p is a list */
    if (!PyList_Check(p))
    {
        printf("[ERROR] Invalid List Object\n");
        return;
    }

    /* Retrieve size of the list and list internals */
    size = ((PyVarObject *)p)->ob_size;  /* Direct access to list size */
    list_object = (PyListObject *)p;  /* Accessing the list object structure */

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", list_object->allocated);

    /* Loop through the list items */
    for (i = 0; i < size; i++)
    {
        item = list_object->ob_item[i];  /* Direct access to list elements */
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);  /* Type of the object */

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

    /* Verify if p is a bytes object */
    if (!PyBytes_Check(p))
    {
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }

    /* Directly access bytes internals */
    size = ((PyVarObject *)p)->ob_size;  /* Access size directly */
    str = ((PyBytesObject *)p)->ob_sval;  /* Access the string representation */

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);
    printf("  trying string: %.*s\n", (int)size, str);

    /* Print the first 6 bytes, including the null terminator if present */
    printf("  first %zd bytes: ", (size < 10) ? size + 1 : 10);
    for (i = 0; i < ((size < 10) ? size + 1 : 10); i++)
    {
        printf("%02x", (unsigned char)str[i]);
        if (i < ((size < 10) ? size : 9))  /* Avoid printing a space after the last byte */
            printf(" ");
    }
    printf("\n");
}

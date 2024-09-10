#include <Python.h>
#include <stdio.h>

/* Function prototypes */
void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints information about a Python list.
 * @p: Pointer to the PyObject list.
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size = PyList_Size(p); /* Get size of the list */
    Py_ssize_t alloc = ((PyListObject *)p)->allocated; /* Get allocated size */
    Py_ssize_t i;

    /* Print the header for Python list information */
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", alloc);

    /* Iterate through list elements and print their type information */
    for (i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);

        /* If the item is a bytes object, print its bytes information */
        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}

/**
 * print_python_bytes - Prints information about a Python bytes object.
 * @p: Pointer to the PyObject bytes object.
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size;
    char *string;
    Py_ssize_t i, limit;

    /* Check if the object is actually a bytes object */
    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    /* Get the size of the bytes object and the string data */
    size = PyBytes_Size(p);
    string = PyBytes_AsString(p);

    /* Print the size and string representation */
    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", string);

    /* Determine the limit of bytes to print (first 10 or size if smaller) */
    limit = size + 1 > 10 ? 10 : size + 1;

    printf("  first %zd bytes:", limit);
    for (i = 0; i < limit; i++)
        printf(" %02x", (unsigned char)string[i]);
    printf("\n");
}

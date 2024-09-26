#include <Python.h>
#include <stdio.h>

/**
 * print_python_float - Prints information about a Python float object
 * @p: PyObject (expected to be a float object)
 */
void print_python_float(PyObject *p)
{
    double value;
    char buffer[64];

    printf("[.] float object info\n");

    /* Check if the object is a valid float object */
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    /* Get the value of the float */
    value = ((PyFloatObject *)p)->ob_fval;

    /* Print the float value */
    snprintf(buffer, sizeof(buffer), "%.15g", value);

    // Check if the value is an integer
    if (value == (int)value) {
        printf("  value: %.1f\n", value);  // Show .0 for integers
    } else {
        printf("  value: %s\n", buffer);
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

    printf("[.] list object info\n");

    /* Check if the object is a valid list object */
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    printf("  size: %zd\n", size);
    printf("  allocated: %zd\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);  // Borrowed reference
        printf("  Element %zd: ", i);
        PyObject_Print(item, stdout, 0);  // Print the item
        printf("\n");
    }
}

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: PyObject (expected to be a bytes object)
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size;
    char *buffer;

    printf("[.] bytes object info\n");

    /* Check if the object is a valid bytes object */
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    buffer = PyBytes_AsString(p);

    printf("  size: %zd\n", size);
    printf("  value: ");
    
    // Print bytes as characters
    for (Py_ssize_t i = 0; i < size; i++)
    {
        // Print the bytes as characters or their integer values
        printf("%02x ", (unsigned char)buffer[i]);
    }
    printf("\n");
}

#include <Python.h>
#include <object.h>
#include <listobject.h>

/**
 * print_python_list_info - Prints basic information 
 * about Python lists.
 * @p: A PyObject representing a Python list.
 *
 * Description: This function prints the 
 * size of the list, the allocated
 * memory, and the type of each element in the list.
 * Return: void
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, alloc, i;
    PyObject *item;

    size = PyList_Size(p);
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", alloc);

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p)
{
	if (!PyList_Check(p))
	{
		printf("[ERROR] Invalid List Object\n");
		return;
	}
	Py_ssize_t size = PyObject_Length(p);
	printf("[*] Size of the Python List = %zd\n", size);
	printf("[*] Allocated = %zd\n", ((PyListObject *)p)->
			allocated);
	printf("[*] Elements:\n");
	for (Py_ssize_t i = 0; i < size; i++)
	{
		PyObject *item = PyList_GetItem(p, i);
		printf("  Element %zd: %s\n", i, Py_TYPE(item)
				->tp_name);
	}
}

void print_python_bytes(PyObject *p)
{
	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
	Py_ssize_t size = PyObject_Length(p);
	printf("[*] Size of the Python Bytes = %zd\n", size);
	printf("[*] First %zd bytes: ", size > 10 ? 10 : size);
	for (Py_ssize_t i = 0; i < (size > 10 ? 10 
				: size); i++)
	{
		printf("%02x", (unsigned char)PyBytes_AS_STRING(p)[i]);
		if (i < (size > 10 ? 9 : size - 1))
		{
			printf(" ");
		}
	}
	printf("\n");
}

void print_python_float(PyObject *p)
{
	if (!PyFloat_Check(p))
	{
		printf("[ERROR] Invalid Float Object\n");
		return;
	}
	double value = PyFloat_AsDouble(p);
	printf("[*] Value of the Python Float = %f\n", value);
}

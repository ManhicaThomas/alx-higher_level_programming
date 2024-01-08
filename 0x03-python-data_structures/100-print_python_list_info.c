#include <Python.h>
#include <object.h>
#include <listobject.h>

void print_python_list_info(PyObject *p)
{
	long int size = PyList_Size(p);
	int index;
	PyListObject *objct = (PyListObject *)p;

	printf("[*] Size of the Python List = %li\n", size);
	printf("[*] Allocated = %li\n", objct->allocated);
	for (index = 0; index < size; index++)
		printf("Element %i: %s\n", index, Py_TYPE(objct->ob_item[index])->tp_name);
}

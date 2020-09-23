#include "library.h"

#include <Python.h>

static PyObject *test(PyObject *self, PyObject *args) {
    int a, b = 0;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return (PyObject *) Py_BuildValue("i", a + b);
}

static PyObject *sub(PyObject *self, PyObject *args) {
    int a, b = 0;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return Py_BuildValue("i", a - b);
}

static struct PyMethodDef TestMethods[] = {
        {"test", test, METH_VARARGS, "ttttt"},
        {"sub",  sub,  METH_VARARGS, "sub a - b"},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
        PyModuleDef_HEAD_INIT,
        "testa",
        "test 1"
        - 1,
        0,
        TestMethods,
};

PyMODINIT_FUNC PyInit_testa(void) {
    return PyModule_Create(&module);
}
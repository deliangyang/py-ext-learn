#include "library.h"

#include <Python.h>


/**
 * https://docs.python.org/3/c-api/arg.html
 * PyArg_ParseTuple 参数类型
 * @param self
 * @param args
 * @return
 */
static PyObject *add(PyObject *self, PyObject *args) {
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

static PyObject *print(PyObject *self, PyObject *args) {
    char *str;
    if (!PyArg_ParseTuple(args, "s", &str)) {
        return NULL;
    }
    print_str(str);
    return Py_BuildValue("s", str);
}

void print_str(char *str) {
    printf("%s\n", str);
}

static PyObject *test_object(PyObject *self, PyObject *args) {
    PyObject *obj;
    if (!PyArg_ParseTuple(args, "O", &obj)) {
        return NULL;
    }

    printf("%s\n", obj->ob_type->tp_doc);
    printf("%s\n", obj->ob_type->tp_name);
    printf("%ld\n", obj->ob_refcnt);

    FILE *file = fopen("test.obj", "w");
    int err = PyObject_Print(obj, file, Py_PRINT_RAW);
    if (err == -1) {
        printf("error: %d", err);
        return NULL;
    }

    PyObject_CallMethod(obj, "a", NULL);

    return Py_BuildValue("O", obj);
}

static struct PyMethodDef TestMethods[] = {
        {"add", add, METH_VARARGS, "add"},
        {"sub",  sub,  METH_VARARGS, "sub a - b"},
        {"print",  print,  METH_VARARGS, "print"},
        {"test_object",  test_object,  METH_VARARGS, "test_object"},
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
//
// Created by root on 12/28/19.
// python3 setup.py build_ext --inplace
//
#include <python3.5/Python.h>

//This is the function that is called from your python code
static PyObject* addList_add(PyObject* self, PyObject* args){

    const int a, b;
    // convert PyObject to C values
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    // 39846434735937786809434447923366044945259881795698604264133945157553621043481
    // 92944559144488390746652316962840371540142975761300035543643590879396054127653
    // get the mpz as a string
    char *s = "70001483889765533507602560540035709086235563548058222767725416808200287388363";

    // convert the string to a python long
    PyObject *l = PyLong_FromString(s, NULL, 10);
    // clean up
    free(s);

    // return it
    return l;

}

//This is the docstring that corresponds to our 'add' function.
static char addList_docs[] =
        "add(  ): add all elements of the list\n";

/* This table contains the relavent info mapping -
   <function-name in python module>, <actual-function>,
   <type-of-args the function expects>, <docstring associated with the function>
 */
static PyMethodDef addList_funcs[] = {
        {"add", (PyCFunction)addList_add, METH_VARARGS, addList_docs},
        {NULL, NULL, 0, NULL}

};

/*
   addList is the module name, and this is the initialization block of the module.
   <desired module name>, <the-info-table>, <module's-docstring>
 */
PyMODINIT_FUNC initaddList(void){
    Py_InitModule3("addList", addList_funcs,
                   "Add all ze lists");

}

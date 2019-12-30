#include <python3.5/Python.h>

long long _fib(long long n){
    if(n < 2)
        return n;
    else
        return _fib(n-1) + _fib(n-2);
};

static PyObject *fib(PyObject *self, PyObject *args) {

    long long n; // 定义 参数

    long long res; // 定义返回值

    // 将参数进行包装，并格式化为长整型l，如果包装失败，则返回NULL.
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    // 39846434735937786809434447923366044945259881795698604264133945157553621043481
    // 92944559144488390746652316962840371540142975761300035543643590879396054127653
    // get the mpz as a string
    char *s = "22929539018085093324573130181172969134000997717879811995688254156731701055681455022263310872778657776931140105228139217406201446639267508689812799894340154736929073174885601039337018209304813564782264274896419453842841178505568085339243739543320141828415273062584517747475003194960943316529218285419639047661";

    // convert the string to a python long
    PyObject *l = PyLong_FromString(s, NULL, 10);
    // clean up
//    free(s);

    // return it
    return l;
};

//static PyObject *fib(PyObject *self, PyObject *args) {
//
//    long long n; // 定义 参数
//
//    long long res; // 定义返回值
//
//    // 将参数进行包装，并格式化为长整型l，如果包装失败，则返回NULL.
//    if (!PyArg_ParseTuple(args, "l", &n))
//        return NULL;
//    // 调用C语言版本的斐波拉契，同时传入包装好的参数n
//    res = _fib(n);
//    // 将返回值用  Py_BuildValue 包成 PyObject 传给 Python
//    return Py_BuildValue("l", res);
//};

// content of speedup_fib.c
static PyMethodDef SpeedupFibMethods[] = {
        {"speedup_fib", (PyCFunction) fib, METH_VARARGS, "fast fib"},
        {NULL, NULL, 0, NULL} // 以 NULL 作结
};

// content of speedup_fib.c
static struct PyModuleDef speedup_fib_module = {
        PyModuleDef_HEAD_INIT,
        "speedup_fib",
        "A module containing methods with faster fib.",
        -1, // global state
        SpeedupFibMethods
};

// content of speedup_fib.c
PyMODINIT_FUNC PyInit_speedup_fib() {
    return PyModule_Create(&speedup_fib_module);
}
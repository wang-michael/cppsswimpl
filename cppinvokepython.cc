//
// Created by root on 12/29/19.
// g++ cppinvokepython.cc -o cppinvokepython -lpython3.5m
// g++ Cryptosystem.cc main.cpp -o sswimpl -L. -lpbc -lgmp

#include "cppinvokepython.hh"
#include "python3.5/Python.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string int2str(int &i) {
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}

int main()
{
    Py_Initialize();        // 初始化
    // 模块所在路径
    string chdir_cmd = string("sys.path.append('/home/michael/graducatepaper/sswpythonimplement/bbox-master/bitbox/pypbc/')");
    const char* cstr_cmd = chdir_cmd.c_str();
    //导入sys，添加模块路径
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(cstr_cmd);
    // 加载模块
    //PyObject* moduleName = PyString_FromString("demo"); //模块名，demo.py
    //PyObject* pModule = PyImport_Import(moduleName);    //python2.7加载模块
    PyObject* pModule = PyImport_ImportModule("mylib");    //python3.5只需要一句话
    //python3.5没有PyString_FromString（有PyUnicode_FromString）
    if (!pModule) // 加载模块失败
    {
        cout << "[ERROR] Python get module failed." << endl;
        int a; cin >> a;
        return 0;
    }
    cout << "[INFO] Python get module succeed." << endl;

    PyObject * pFunc = NULL;
    PyObject* pDict = NULL;
    PyObject* pClass = NULL;
    PyObject* pIns = NULL;

    pDict = PyModule_GetDict(pModule);
    assert(pDict != NULL);

    pClass = PyDict_GetItemString(pDict, "MyCryptosystem");
    assert(pClass != NULL);

    pIns = PyObject_CallObject(pClass, NULL);
    assert(pIns != NULL);

    PyObject* args = PyTuple_New(2);       // 2个参数
    PyObject* arg1 = PyLong_FromLong(10);    // 参数一设为，字符串
    PyObject* arg2 = PyLong_FromLong(256);    // 参数二设为，一个整数，用long表示
    PyTuple_SetItem(args, 0, arg1);
    PyTuple_SetItem(args, 1, arg2);

    pIns = PyObject_CallMethod(pIns, "new", "O", args);

    int vector1[10];
    for (int i = 0; i < 10; ++i) {
        vector1[i] = 0;
    }
    vector1[0] = 3, vector1[1] = -2;

    int token[10];
    for (int i = 0; i < 10; ++i) {
        token[i] = 0;
    }
    token[0] = 2, token[1] = 3;

    string vector1str = "", tokenstr = "";
    for (int j = 0; j < 9; ++j) {
        vector1str += int2str(vector1[j]);
        vector1str += ",";
        tokenstr += int2str(token[j]);
        tokenstr += ",";
    }
    vector1str += int2str(vector1[9]);
    tokenstr += int2str(token[9]);

    cout << vector1str << "     " << tokenstr << endl;

    // 加密数据
    PyObject* argsForEncrypt = PyTuple_New(1);
    PyObject* arg1ForEncrypt = Py_BuildValue("s", "3,-2,0,0,0,0,0,0,0,0");    // 参数一设为，字符串
    PyTuple_SetItem(argsForEncrypt, 0, arg1ForEncrypt);

    PyObject* pRet = PyObject_CallMethod(pIns, "encrypt", "O", argsForEncrypt);

    const char* encryptRes = PyUnicode_AsUTF8(pRet);

    // 加密token
    PyObject* argsForToken = PyTuple_New(1);
    PyObject* arg1ForToken = Py_BuildValue("s", "2,3,0,0,0,0,0,0,0,0");    // 参数一设为，字符串
    PyTuple_SetItem(argsForToken, 0, arg1ForToken);

    PyObject* pRet1 = PyObject_CallMethod(pIns, "genToken", "O", argsForToken);

    const char* encryptToken = PyUnicode_AsUTF8(pRet1);

    PyObject* argsForQuery = PyTuple_New(2);       // 2个参数
    PyObject* arg1ForQuery = Py_BuildValue("s", encryptRes);    // 参数一设为，字符串
    PyObject* arg2ForQuery = Py_BuildValue("s", encryptToken);    // 参数二设为，一个整数，用long表示
    PyTuple_SetItem(argsForQuery, 0, arg1ForQuery);
    PyTuple_SetItem(argsForQuery, 1, arg2ForQuery);

    PyObject* pRet2 = PyObject_CallMethod(pIns, "query", "O", argsForQuery);

    cout << PyLong_AsLong(pRet2) << endl;


    std::cout << "<finished>";
    Py_DECREF(pIns);

//    // 加载函数
//    PyObject* pv = PyObject_GetAttrString(pModule, "test_add");
//    if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
//    {
//        cout << "[ERROR] Can't find funftion (test_add)" << endl;
//        int a; cin >> a;
//        return 0;
//    }
//    cout << "[INFO] Get function (test_add) succeed." << endl;
//    // 设置参数
//    PyObject* args = PyTuple_New(2);       // 2个参数
//    PyObject* arg1 = PyLong_FromLong(1);    // 参数一设为，字符串
//    PyObject* arg2 = PyLong_FromLong(520);    // 参数二设为，一个整数，用long表示
//    PyTuple_SetItem(args, 0, arg1);
//    PyTuple_SetItem(args, 1, arg2);
//    // 调用函数
//    PyObject* pRet = PyObject_CallObject(pv, args);
//    // 获取参数
//    if (pRet)  // 验证是否调用成功
//    {
//        long result = PyLong_AsLong(pRet);
//        //string result = PyUnicode_AsUTF8(pRet);     //返回字符串
//        cout << "result:" << result << endl;
//    }

    Py_Finalize();      // 释放资源
    return 0;
}


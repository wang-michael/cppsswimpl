cmake_minimum_required(VERSION 3.13)
project(cppsswimpl)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppsswimpl main.cpp Cryptosystem.cc demomodule.c sample.h pysample.c speedup_fib.c cppinvokepython.cc cppinvokepython.hh)
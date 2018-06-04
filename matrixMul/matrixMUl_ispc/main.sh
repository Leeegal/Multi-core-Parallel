#! /bin/bash
make
clang++ objs/matrixMul_ispc.o objs/matrixMul.o -o objs/a.out
./objs/a.out


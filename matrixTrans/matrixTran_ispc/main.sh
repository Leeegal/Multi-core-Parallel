#! /bin/bash
make
clang++ objs/matrixTran_ispc.o objs/matrixTran.o -o objs/a.out
./objs/a.out


#! /bin/bash
make
clang++ objs/calculatePI_ispc.o objs/calculatePI.o -o ./objs/a.out
./objs/a.out


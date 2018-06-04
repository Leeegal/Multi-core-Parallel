#! /bin/bash
make
g++ objs/calculatePI_ispc.o objs/calculatePI.o
./objs/a.out


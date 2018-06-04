
CXX=clang++ -m64
CXXFLAGS=-Iobjs/ -O3 -Wall
ISPC=ispc
ISPCFLAGS=-O2 --arch=x86-64 --target=sse2

default: matrixMul

.PHONY: dirs clean
.PRECIOUS: objs/matrixMul.h

dirs:
	/bin/mkdir -p objs/

clean:
	/bin/rm -rf objs *~ matrixMul

matrixMul: dirs  objs/matrixMul.o objs/matrixMul_ispc.o
	$(CXX) $(CXXFLAGS) -o $@ objs/matrixMul.o objs/matrixMul_ispc.o

objs/matrixMul.o: matrixMul.cpp objs/matrixMul_ispc.h 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

objs/%_ispc.h objs/%_ispc.o: %.ispc
	$(ISPC) $(ISPCFLAGS) $< -o objs/$*_ispc.o -h objs/$*_ispc.h

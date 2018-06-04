
CXX=clang++ -m64
CXXFLAGS=-Iobjs/ -O3 -Wall
ISPC=ispc
ISPCFLAGS=-O2 --arch=x86-64 --target=sse2

default: matrixTran

.PHONY: dirs clean
.PRECIOUS: objs/matrixTran.h

dirs:
	/bin/mkdir -p objs/

clean:
	/bin/rm -rf objs *~ matrixTran

matrixTran: dirs  objs/matrixTran.o objs/matrixTran_ispc.o
	$(CXX) $(CXXFLAGS) -o $@ objs/matrixTran.o objs/matrixTran_ispc.o

objs/matrixTran.o: matrixTran.cpp objs/matrixTran_ispc.h 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

objs/%_ispc.h objs/%_ispc.o: %.ispc
	$(ISPC) $(ISPCFLAGS) $< -o objs/$*_ispc.o -h objs/$*_ispc.h

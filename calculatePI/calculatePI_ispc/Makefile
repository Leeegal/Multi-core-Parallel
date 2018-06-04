
CXX=g++ -m64
CXXFLAGS=-Iobjs/ -O3 -Wall
ISPC=ispc
ISPCFLAGS=-O2 --arch=x86-64 --target=sse2

default: calculatePI

.PHONY: dirs clean
.PRECIOUS: objs/calculatePI.h

dirs:
	/bin/mkdir -p objs/

clean:
	/bin/rm -rf objs *~ calculatePI

calculatePI: dirs  objs/calculatePI.o objs/calculatePI_ispc.o
	$(CXX) $(CXXFLAGS) -o $@ objs/calculatePI.o objs/calculatePI_ispc.o

objs/calculatePI.o: calculatePI.cpp objs/calculatePI_ispc.h 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

objs/%_ispc.h objs/%_ispc.o: %.ispc
	$(ISPC) $(ISPCFLAGS) $< -o objs/$*_ispc.o -h objs/$*_ispc.h

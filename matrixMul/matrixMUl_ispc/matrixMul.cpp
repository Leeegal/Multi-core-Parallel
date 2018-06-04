#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <chrono>

#include "matrixMul_ispc.h"
using namespace ispc;

#define PALNUM 5

void init(int a[][PALNUM]) {
    int num = 1;
    for(int i = 0; i < PALNUM; i++) {
      for(int j = 0; j < PALNUM; j++) {
        a[i][j] = num ++;
      }
    }
}

void printMatrix(int a[][PALNUM]) {
    // int num = 1;
    for(int i = 0; i < PALNUM; i++) {
      for(int j = 0; j < PALNUM; j++) {
        std::cout <<  a[i][j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int a[PALNUM][PALNUM];
    int b[PALNUM][PALNUM];
    int result[PALNUM][PALNUM];
    init(a); printMatrix(a);
    init(b); printMatrix(b);
   
    auto start = std::chrono::system_clock::now();

    matrixMul(a, b, result, PALNUM-1);

    auto end = std::chrono::system_clock::now();
    printMatrix(result);
    std::chrono::duration<double> diff = end-start;
    std::cout << "time: " << diff.count() << std::endl;

    return 0;

}
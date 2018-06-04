#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <chrono>

#include "matrixTran_ispc.h"
using namespace ispc;

#define PALNUM 500

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
    int result[PALNUM][PALNUM];

    init(a); 
    // printMatrix(a);
   
    auto start = std::chrono::system_clock::now();

    matrixTran(a, result, PALNUM-1);

    auto end = std::chrono::system_clock::now();
    // printMatrix(result);
    std::chrono::duration<double> diff = end-start;
    std::cout << "time: " << diff.count() << std::endl;

    return 0;

}
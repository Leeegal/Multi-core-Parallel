#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <chrono>

#include "calculatePI_ispc.h"
using namespace ispc;

#define PALNUM 10000

int main() {
    std::cout << "问题规模： " << PALNUM << std::endl;
    auto start = std::chrono::system_clock::now();

    double sum = calPi(PALNUM);

    
    std::cout << "PI: " << sum << std::endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "time: " << diff.count() << std::endl;

    return 0;

}
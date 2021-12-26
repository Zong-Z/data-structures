#include <iostream>
#include <chrono>
#include <vector>

#include "Vector/Vector.h"

int main() {
    std::size_t numberOfIterations = 10000, numberOfElements = 2048;
    std::chrono::nanoseconds averageDuration, duration{};
    std::chrono::steady_clock::time_point start, stop;
    std::cout << "STL implementation of the vector, ";
    for (std::size_t i = 0; i < numberOfIterations; ++i) {
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::size_t> v;
        for (std::size_t j = 0; j < numberOfElements; ++j)
            v.push_back(j + 1);

        stop = std::chrono::high_resolution_clock::now();
        duration += stop - start;
    }

    averageDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(duration / numberOfIterations);
    std::cout << "execution time : " << averageDuration.count() << " nanoseconds." << std::endl;

    std::cout << "Own implementation of the vector, ";
    for (std::size_t i = 0; i < numberOfIterations; ++i) {
        start = std::chrono::high_resolution_clock::now();
        Vector<std::size_t> v;
        for (std::size_t j = 0; j < numberOfElements; ++j)
            v.pushBack(j + 1);

        stop = std::chrono::high_resolution_clock::now();
        duration += stop - start;
    }

    averageDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(duration / numberOfIterations);
    std::cout << "execution time : " << averageDuration.count() << " nanoseconds." << std::endl;

    return EXIT_SUCCESS;
}

#include <iostream>
#include <vector>

#include "Vector/Vector.h"

int main() {
    {
        Vector<std::size_t> vector;
        for (std::size_t i = 0; i < 10; ++i)
            vector.pushBack(i + 1);

        std::cout << *(vector.end() - 1) << std::endl;
    }

    return EXIT_SUCCESS;
}

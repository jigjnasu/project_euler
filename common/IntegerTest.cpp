#include "Integer.h"
#include <ctime>

void test() {
    std::clock_t start = clock();
    PROJECT_EULER::COMMON::Integer<int> A(0);
    PROJECT_EULER::COMMON::Integer<int> B(5);
    for (int i = 0; i < 1000; ++i) {
        A += B;
    }
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    A.Print();
}

int main() {
    test();

    return 0;
}

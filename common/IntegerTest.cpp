#include "Integer.h"
#include <cstdio>
#include <ctime>

int main() {
    std::clock_t start = clock();
    PROJECT_EULER::COMMON::Integer<int> A(0);
    PROJECT_EULER::COMMON::Integer<int> B(1);
    for (int i = 0; i < 50000; ++i) {
        PROJECT_EULER::COMMON::Integer<int> C = A + B;
        A = B;
        B = C;
    }
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    B.Print();
    return 0;
}

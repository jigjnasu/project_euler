#include "common/Integer.h"
#include <cstdio>
#include <ctime>

void fibonacci() {
    PROJECT_EULER::COMMON::Integer A(1);
    PROJECT_EULER::COMMON::Integer B(1);
    PROJECT_EULER::COMMON::Integer C = A + B;
    int index = 3;
    
    while (C.Size() < 1000) {
	A = B;
	B = C;
	C = A + B;
	++index;
    }
    printf("Index == [%d]\n", index);
}

int main() {
    std::clock_t start = clock();
    fibonacci();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    return 0;
}

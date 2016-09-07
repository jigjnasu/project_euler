#include "common/Integer.h"
#include <cstdio>
#include <ctime>

namespace PC = PROJECT_EULER::COMMON;

void fibonacci() {
    PC::Integer<int> A(1);
    PC::Integer<int> B(1);
    PC::Integer<int> C = A + B;
    int index = 3;

    while (C.GetData().size() < 1000) {
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

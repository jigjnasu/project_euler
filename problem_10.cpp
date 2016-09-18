#include "common/Integer.h"
#include <cstdio>
#include <cmath>
#include <ctime>

bool is_prime(const unsigned long long int& N) {
    for (int i = 2; i <= std::sqrt(N); ++i)
	if (N % i == 0)
	    return false;

    return true;
}

int main() {
    std::clock_t start = clock();
    PROJECT_EULER::COMMON::Integer sum;
    for (int i = 2; i < 2000000; ++i) {
	if (is_prime(i)) {
	    sum += i;
	}
    }

    sum.Print();
    printf("Execution time == [%.8f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
    return 0;
}

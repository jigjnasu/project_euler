/*
  This is solution for problem 48 (Self Powers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
*/

#include "common/Integer.h"
#include <cstdio>
#include <ctime>

Integer power(const int& x, const int& n) {
    if (n == 1) {
        return Integer(x);
    } else {
        if (n % 2 == 0) {
            Integer value = power(x, n / 2);
            return value * value;
        } else {
            Integer value = power(x, n / 2);
            return value * value * x;
        }
    }
}

void self_powers() {
    Integer power_sum(0);

    for (int i = 1; i <= 1000; ++i) {
        Integer number = power(i, i);
	power_sum += number;
    }

    printf("Self power sum is here ----> \n");
    power_sum.Print();
    printf("\n");
}

int main() {
    std::clock_t start = clock();
    self_powers();
    printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    return 0;
}

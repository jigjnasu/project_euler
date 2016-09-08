/*
  This is solution for problem 48 (Self Powers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
*/

#include "common/Integer.h"
#include <cstdio>
#include <ctime>


void self_powers() {
    PROJECT_EULER::COMMON::Integer<int> power_sum(0);

    for (int i = 1; i <= 1000; ++i) {
	PROJECT_EULER::COMMON::Integer<int> number(1);
	for (int j = 0; j < i; ++j) {
	    number *= i;
	}
	power_sum += number;
    }

    printf("Selft power sum == [%s]\n", power_sum.GetStringData().c_str());
}

int main() {
    std::clock_t start = clock();
    self_powers();
    printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    return 0;
}

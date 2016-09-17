/*
  This is solution for problem 29 (Distinct Powers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "common/Integer.h"
#include <cstdio>
#include <ctime>
#include <set>
#include <cmath>

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

void count_distinct_powers() {
    std::set<std::string> distinct_numbers;
    for (int a = 2; a <= 100; ++a) {
	for (int b = 2; b <= 100; ++b) {
	    Integer number = power(a, b);
	    distinct_numbers.insert(number.GetReverse());
	}
    }

    printf("Distinct powers count == [%lu]\n", distinct_numbers.size());
}

int main() {
    std::clock_t start = clock();
    count_distinct_powers();
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    return 0;
}


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

void count_distinct_powers() {
	std::set<std::string> distinct_numbers;
	for (int a = 2; a <= 100; ++a) {
		for (int b = 2; b <= 100; ++b) {
			PROJECT_EULER::COMMON::Integer<int> number(a);
			for (int i = 1; i < b; ++i) {
				number *= a;
			}
			distinct_numbers.insert(number.GetStringData());
		}
	}

	printf("Distinct powers count == [%d]\n", distinct_numbers.size());
}

int main() {
	std::clock_t start = clock();
	count_distinct_powers();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}


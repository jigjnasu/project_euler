/*
  This is solution for problem 32 (Pandigital products) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include "common/QuickSort.h"
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

bool is_pandigital(std::string number) {
	PROJECT_EULER::COMMON::QuickSort<char> sort;
	sort.Sort(number);

	if (number.size() != 9)
		return false;

	for (int i = 0; i < 9; ++i)
		if (number[i] - '0' != i + 1)
			return false;

	return true;
}

std::string number_to_string(const int& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

void pandigital_products() {
	int product_sum = 0;
	for (int a = 1; a <= ; ++a) {
		for (int b = 1; b <= ; ++b) {
			const int c = a * b;
			std::string number = number_to_string(a) + number_to_string(b) + number_to_string(c);
			if (is_pandigital(number))
				product_sum += c;
		}
	}

	printf("Product sum of all pandigital numbers == [%d]\n", product_sum);
}

int main() {
	std::clock_t start = clock();
	pandigital_products();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

#include "common/QuickSort.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sstream>

typedef unsigned long long int u_long;

bool is_pandigital(std::string number) {
	if (number.size() != 9)
		return false;

	PROJECT_EULER::COMMON::QuickSort<char> sort;
	sort.Sort(number);

	for (std::size_t i = 0; i < 9; ++i)
		if (number[i] - '0' != i + 1)
			return false;

	return true;
}

std::string number_to_string(const int& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

void largest_pandigital_multiples() {
	std::string largest_number;
	for (int i = 1; i <= 10000; ++i) {
		std::string number;
		int j = 1;
		while (1) {
			number += number_to_string(i * j);
			if (number.size() >= 9) {
				if (is_pandigital(number)) {
					if (number > largest_number)
						largest_number = number;
				}
				break;
			}
			++j;
		}
	}

	printf("Largest pandigtial multiple number == [%s]\n", largest_number.c_str());
}

int main() {
	std::clock_t start = clock();
	largest_pandigital_multiples();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}

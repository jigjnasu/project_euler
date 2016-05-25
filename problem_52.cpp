/*
  This is solution for problem 52 (Permuted multiples) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
 */

#include "common/QuickSort.h"
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>

std::string number_to_string(const int& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

bool all_permutated(std::string X1, std::string X2,
					std::string X3, std::string X4,
					std::string X5, std::string X6) {
	if (X1.size() != X2.size() ||
		X1.size() != X3.size() ||
		X1.size() != X4.size() ||
		X1.size() != X5.size() ||
		X1.size() != X6.size())
		return false;

	PROJECT_EULER::COMMON::QuickSort<char> sort;
	sort.Sort(X1);
	sort.Sort(X2);
	sort.Sort(X3);
	sort.Sort(X4);
	sort.Sort(X5);
	sort.Sort(X6);

	for (std::size_t i = 0; i < X1.size(); ++i)
		if (X1[i] != X2[i] || X1[i] != X3[i] || X1[i] != X4[i] || X1[i] != X5[i] || X1[i] != X6[i])
			return false;
}

void permutated_multiples() {
	int i = 2;
	while (1) {
		if (all_permutated(number_to_string(i * 1),
						   number_to_string(i * 2),
						   number_to_string(i * 3),
						   number_to_string(i * 4),
						   number_to_string(i * 5),
						   number_to_string(i * 6))) {
			printf("1 * %d == [%d]\n", i, i * 1);
			printf("2 * %d == [%d]\n", i, i * 2);
			printf("3 * %d == [%d]\n", i, i * 3);
			printf("4 * %d == [%d]\n", i, i * 4);
			printf("5 * %d == [%d]\n", i, i * 5);
			printf("6 * %d == [%d]\n", i, i * 6);
			
			break;
		}
		++i;
	}
}

int main() {
	std::clock_t start = clock();
	permutated_multiples();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

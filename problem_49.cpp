/*
  This is solution for problem 49 (Prime Permutations) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include "common/QuickSort.h"
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <sstream>

bool is_permutation(std::string A, std::string B, std::string C) {
	PROJECT_EULER::COMMON::QuickSort<char> sort;
	sort.Sort(A);
	sort.Sort(B);
	sort.Sort(C);

	for (std::size_t i = 0; i < A.size(); ++i)
		if (A[i] != B[i] || A[i] != C[i])
			return false;
	return true;
}

bool is_prime(const int& N) {
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

std::string number_to_string(const int& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

void prime_permutations() {
	const int start_number = 1000;
	const int end_number = 9999;

	for (int i = start_number; i <= end_number; ++i) {
		if (is_prime(i)) {
			for (int j = i + 1; j <= end_number; ++j) {
				if (is_prime(j)) {
					const int third_number = j + (j - i);
					if (third_number <= end_number && is_prime(third_number)) {
						std::string A = number_to_string(i);
						std::string B = number_to_string(j);
						std::string C = number_to_string(third_number);

						if (is_permutation(A, B, C)) {
							printf("prime permutations == [%s]\n", std::string(A + B + C).c_str());
						}
					}
				}
			}
		}
	}
}

int main() {
	std::clock_t start = clock();
	prime_permutations();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

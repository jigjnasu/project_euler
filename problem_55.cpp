/*
  This is solution for problem 55 (Lychrel numbers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 2nd, 2016
 */

#include "common/Integer.h"
#include <cstdio>
#include <ctime>

namespace PC = PROJECT_EULER::COMMON;

PC::Integer<int> reverse(const PC::Integer<int>& number) {
	const std::vector<int> N = number.GetData();
	std::vector<int> temp;
	for (int i = N.size() - 1; i >= 0; --i)
		temp.push_back(N[i]);

	return PC::Integer<int> (temp);
}

bool is_palindrome(const PC::Integer<int>& number) {
	const std::vector<int> N = number.GetData();
	int j = N.size() - 1;
	for (std::size_t i = 0; i < j; ++i, --j)
		if (N[i] != N[j])
			return false;
	return true;
}

bool is_lychrel_number(const int& N) {
	PC::Integer<int> number(N);
	for (int i = 0; i < 50; ++i) {
		number += reverse(number);
		if (is_palindrome(number))
			return false;
	}

	return true;
}

int lychrel_numbers(const int& MAX) {
	int count = 0;
	for (int i = 10; i < MAX; ++i)
		if (is_lychrel_number(i))
			++count;

	return count;
}

int main() {
	std::clock_t start = clock();
	const int MAX = 10000;
	printf("Lychrel numbers under %d == [%d]\n", MAX, lychrel_numbers(MAX));
	printf("Ëxecution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}

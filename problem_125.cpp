/*
  This is solution for problem 125 (Palindromic sums) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 3rd, 2016
 */

#include <cstdio>
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

typedef unsigned long long int u_long;
const u_long MAX = 100000000;

std::string number_to_string(const u_long& N) {
	std::stringstream ss;
	ss << N;
	return ss.str();
}

bool is_palindrome(const std::string& number) {
	int j = number.size() - 1;
	for (std::size_t i = 0; i < j; ++i, --j)
		if (number[i] != number[j])
			return false;
	
	return true;
}

void palindromic_sums() {
	const int limit = std::sqrt(MAX);
	std::set<u_long> numbers;
	u_long sum_of_numbers = 0;

	for (int i = 1; i <= limit; ++i) {
		u_long number = i * i;
		for (int j = i + 1; j <= limit; ++j) {
			number += j * j;

			if (number > MAX)
				break;

			if (is_palindrome(number_to_string(number)))
				numbers.insert(number);
		}
	}

	for (std::set<u_long>::const_iterator it = numbers.begin();
		 it != numbers.end(); ++it)
		sum_of_numbers += *it;
	
	printf("--------------------------------------------------------\n");
	printf("Sum of all numbers below 10 ^ 8 == [%llu]\n", sum_of_numbers);
	printf("--------------------------------------------------------\n");
}


int main() {
	std::clock_t start = clock();
	palindromic_sums();
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

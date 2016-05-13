/*
  This is solution for problem 50 (Consecutive prime sum) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
 */

#include <cstdio>
#include <ctime>
#include <cmath>
#include <vector>

const int MILLION = 1000000;

bool is_prime(const int& N) {
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

void get_prime_sums(std::vector<int>& prime_sums) {
	prime_sums.push_back(2);
	int last_sum = 2;
	int iter = 3;
	while (1) {
		if (is_prime(iter)) {
			if (iter + last_sum > MILLION)
				break;
			prime_sums.push_back(iter + last_sum);
			last_sum += iter;
		}
		++iter;
	}
}

int get_largest_sum(std::vector<int>& prime_sums) {
	int longest_chain = 0;
	int largest_number = 0;
	for (int i = prime_sums.size() - 1; i > 0; --i) {
		int chain = 0;
		int number = 0;
		for (int j = 0; j < i; ++j) {
			if (is_prime(prime_sums[i] - prime_sums[j])) {
				chain = i - j;
				if (chain > longest_chain) {
					longest_chain = chain;
					largest_number = prime_sums[i] - prime_sums[j];
				}
			}
		}
	}

	printf("-----------------------------------------------------------\n");
	printf("Largest consecutive prime number == [%d]\n", largest_number);
	printf("-----------------------------------------------------------\n");
}

void consecutive_prime_sum() {
	std::vector<int> prime_sums;
	get_prime_sums(prime_sums);
	get_largest_sum(prime_sums);
}

int main() {
	std::clock_t start = clock();
	consecutive_prime_sum();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}

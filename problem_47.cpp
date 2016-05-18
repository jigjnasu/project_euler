/*
  This is solution for problem 46 (Goldbach's other conjecture) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>

bool is_prime(const int& N) {
	if (N == 2)
		return true;
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

void get_factors(const int& N, std::vector<int>& factors,  const std::vector<int>& prime_numbers) {
	if (prime_numbers.size()) {
		int number = N;
		int prime_iter = 0;
		while (number != 1 && prime_numbers[prime_iter] <= N / 2) {
			int factor = 1;
			while (number % prime_numbers[prime_iter] == 0) {
				factor *= prime_numbers[prime_iter];
				number /= prime_numbers[prime_iter];
			}
			if (factor != 1)
				factors.push_back(factor);
			++prime_iter;
		}
	}
}

bool is_distinct_factor(const std::vector<int>& factors) {
	if (factors.size() != 16)
		return false;

	for (std::size_t i = 0; i < factors.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < factors.size(); ++j) {
			if (factors[i] == factors[j])
				return false;
		}
	}

	return true;
}

void print(const int& number, const std::vector<int>& factors) {
	printf("[%d] ==== ", number);
	for (std::size_t i = 0; i < factors.size(); ++i)
		printf("[%8d] ", factors[i]);
	printf("\n");
}

void distinct_prime_factors() {
	std::vector<int> factor_A;
	std::vector<int> factor_B;
	std::vector<int> factor_C;
	std::vector<int> prime_numbers;
	
	int i = 2;
	get_factors(2, factor_A, prime_numbers);
	get_factors(3, factor_B, prime_numbers);
	get_factors(4, factor_C, prime_numbers);
		
	while (1) {
		std::vector<int> factor_D;
		
		if (is_prime(i))
			prime_numbers.push_back(i);

		get_factors(i + 3, factor_D, prime_numbers);

		std::vector<int> factors;
		factors.insert(factors.end(), factor_A.begin(), factor_A.end());
		factors.insert(factors.end(), factor_B.begin(), factor_B.end());
		factors.insert(factors.end(), factor_C.begin(), factor_C.end());
		factors.insert(factors.end(), factor_D.begin(), factor_D.end());

		if (is_distinct_factor(factors)) {
			print(i, factor_A);
			print(i + 1, factor_B);
			print(i + 2, factor_C);
			print(i + 3, factor_D);
			break;
		}

		factor_A = factor_B;
		factor_B = factor_C;
		factor_C = factor_D;
		
		++i;
	}
}

int main() {
	std::clock_t start = clock();
	distinct_prime_factors();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

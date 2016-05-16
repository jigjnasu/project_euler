/*
  This is solution for problem 46 (Goldbach's other conjecture) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>

bool is_prime(const int& N) {
	if (N <= 2)
		return true;

	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;

	return true;
}

bool is_goldbach_conjecture(const int& N, std::vector<int>& prime_numbers) {
	int prime_iter = 0;
	while (prime_numbers[prime_iter] < N) {
		int power = 1;
		while (1) {
			const int number = prime_numbers[prime_iter] + (2 * power * power);
			if (number == N)
				return true;
			if (number > N)
				break;
			++power;
		}
		
		++prime_iter;
	}

	return false;
}

void goldbach_conjecture() {
	std::vector<int> prime_numbers;

	int number = 2;
	while (1) {
		if (is_prime(number)) {
			prime_numbers.push_back(number);
		} else {
			if (number % 2) {
				if (!is_goldbach_conjecture(number, prime_numbers)) {
					printf("Goldbach's Other Conjucture has been broken at [%d]\n", number);
					break;
				}
			}
		}
		++number;
	}
}


int main() {
	std::clock_t start = clock();
	goldbach_conjecture();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

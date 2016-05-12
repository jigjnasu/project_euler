/*
  This is solution for problem 27 (Quadratic primes) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include <cstdio>
#include <cmath>
#include <ctime>

bool is_prime(const int& N) {
	for (int i = 2; i < std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

int solve_quadratic_prime(const int& a, const int& b, const int& n) {
	return std::abs((n * n) + (a * n) + b);
}

void qudratic_primes() {
	int largest_a = 0;
	int largest_b = 0;
	int largest_n = 0;
	for (int a = -1000; a <= 1000; ++a) {
		for (int b = -1000; b <= 1000; ++b) {
			int n = 0;
			while (is_prime(solve_quadratic_prime(a, b, n)))
				++n;

			if (n > largest_n) {
				largest_a = a;
				largest_b = b;
				largest_n = n;
			}
		}
	}

	printf("product of a and b == [%d]\n", largest_a * largest_b);
}

int main() {
	std::clock_t start = clock();
	qudratic_primes();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

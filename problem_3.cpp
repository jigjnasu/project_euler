#include <cstdio>
#include <cmath>
#include <ctime>

bool is_prime(const unsigned long long int& N) {
	for (unsigned long long int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

void largest_factor(const unsigned long long int& N) {
	for (unsigned long long int i = std::sqrt(N); i >= 2; --i) {
		if (N % i == 0) {
			if (is_prime(i)) {
				printf("largest factor == [%llu]\n", i);
				break;
			}
		}
	}
}

int main() {
	std::clock_t start = clock();
	unsigned long long int N = 600851475143;
	largest_factor(N);
	std::clock_t end = clock();

	printf("Execution time == [%.2f] seconds\n", (end - start) / CLOCKS_PER_SEC);

	return 0;
}

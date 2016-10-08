#include <cstdio>
#include <cmath>
#include <ctime>

bool is_prime(const unsigned long long int& N) {
	for (unsigned long long int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;

	return true;
}

void print_prime_number(const int& N) {
	int i = 0;
	int n = 2;
	while (1) {
		if (is_prime(n))
			++i;

		if (i >= N)
			break;

		++n;
	}

	printf("%d prime number == [%d]\n", i, n);
}

int main() {
	std::clock_t start = clock();
	print_prime_number(10001);
	printf("Execution time == [%.2f]\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	return 0;
}

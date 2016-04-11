#include "Integer.h"
#include <cmath>
#include <ctime>

bool is_prime(const unsigned long long int& N) {
	for (unsigned long long int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;

	return true;
}

int main() {
	std::clock_t start = clock();
	Integer<unsigned long long int> sum(0);
	for (unsigned long long int i = 2; i < 2000000; ++i) {
		if (is_prime(i)) {
			Integer<unsigned long long int> temp(i);
			sum = sum + temp;
		}
	}

	sum.Print();

	printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	return 0;
}

#include <cstdio>
#include <cmath>
#include <ctime>

bool is_digit_fifth_power(const int& N) {
	unsigned long long int temp = N;
	unsigned long long int sum = 0;

	while (temp) {
		int value = temp % 10;
		sum += std::pow(value, 5);
		temp /= 10;
	}

	if (N != sum)
		return false;
	
	return true;
}

void sum() {
	unsigned long long int sum = 0;
	for (unsigned long long int i = 2; i <= 1000000; ++i)
		if (is_digit_fifth_power(i))
			sum += i;
	printf("Sum of digit of fifth powers == [%llu]\n", sum);
}

int main() {
	std::clock_t start = clock();
	sum();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

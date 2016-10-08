#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>

bool is_prime(const int& N) {
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	
	return true;
}

void rotate_left(std::string& number) {
	const char first = number[0];
	for (int i = 1; i < number.size(); ++i)
		number[i - 1] = number[i];
	number[number.size() - 1] = first;
}

std::string number_to_string(int N) {
	std::string number;
	while (N) {
		number.push_back((N % 10) + '0');
		N /= 10;
	}
	return number;
}

bool is_circular_prime(std::string number) {
	for (std::size_t i = 0; i < number.size(); ++i) {
		if (!is_prime(std::atoi(number.c_str())))
			return false;
		rotate_left(number);
	}

	return true;
}

void count_circular_primes() {
	int counter = 0;
	for (int i = 2; i < 1000000; ++i)
		if (is_circular_prime(number_to_string(i)))
			++counter;

	printf("Circular primes under million == [%d]\n", counter);
}

int main() {
	std::clock_t start = clock();
	count_circular_primes();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

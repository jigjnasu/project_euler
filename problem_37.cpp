#include <cstdio>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

typedef unsigned long long int u_long;

bool is_prime(const u_long& N) {
	if (N < 2)
		return false;
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;

	return true;
}

std::string number_to_string(u_long N) {
	std::string number;
	while (N) {
		number.push_back(N % 10 + '0');
		N /= 10;
	}

	std::reverse(number.begin(), number.end());
	return number;
}

bool check_trunctable_prime(const std::string& number) {
	if (!is_prime(std::atoi(number.c_str())))
		return false;

	for (int i = 1; i < number.size(); ++i)
		if (!is_prime(std::atoi(number.substr(0, i).c_str())))
			return false;
	for (int i = number.size() - 1; i >= 1; --i)
		if (!is_prime(std::atoi(number.substr(i, number.size() - i).c_str())))
			return false;

	return true;
}

void truncatable_primes() {
	u_long sum = 0;
	u_long iter = 10;
	int counter = 0;
	while (counter < 11) {
		if (check_trunctable_prime(number_to_string(iter))) {
			sum += iter;
			++counter;
		}
		++iter;
	}

	printf("Sum of 11 truncatable primes == [%llu]\n", sum);
}

int main() {
	std::clock_t start = clock();
	truncatable_primes();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

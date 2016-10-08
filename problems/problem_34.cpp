#include <cstdio>
#include <ctime>
#include <vector>

typedef unsigned long long int u_long;

int factorial(const int& N) {
	if (N <= 1)
		return 1;
	return N * factorial(N - 1);
}

bool is_equal(const u_long& N, std::vector<int>& factorials) {
	int sum = 0;
	int T = N;
	while (T) {
		sum += factorials[T % 10];
		T /= 10;
	}

	return sum == N;
}

void digit_factorials() {
	// Pre calculations of factorials from 0 to 9
	std::vector<int> factorials;
	for (int i = 0; i < 10; ++i)
		factorials.push_back(factorial(i));

	u_long sum = 0;
	for (u_long i = 3; i < 10000000; ++i)
		if (is_equal(i, factorials))
			sum += i;
	
	printf("Sum of digit factorials == [%llu]\n", sum);
}

int main() {
	std::clock_t start = clock();
	digit_factorials();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

/*
  This is solution for problem 44 (Pentagon numbers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
 */

#include <cstdio>
#include <ctime>
#include <cmath>

int pentagon_number(const int& N) {
	return (N * ((3 * N) - 1)) / 2;
}

bool is_pentagon_number(const unsigned long long int& number) {
	const float N = (1 + std::sqrt(24 * number + 1)) / 6;
	if (N - static_cast<int>(N) > 0.0)
		return false;
	
	return true;
}

void find_min_difference() {
	int p = 1;
	while (1) {
		const int A = pentagon_number(p);

		for (int q = p - 1; q > 0; --q) {
			const int B = pentagon_number(q);
			if (is_pentagon_number(A + B) && is_pentagon_number(A - B)) {
				printf("------------------------------------------------------\n");
				printf("Sum == [%d] || Difference == [%d]\n", A + B, A - B);
				printf("------------------------------------------------------\n");
				return;
			}
		}
		++p;
	}
}

int main() {
	std::clock_t start = clock();
	find_min_difference();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	
	return 0;
}

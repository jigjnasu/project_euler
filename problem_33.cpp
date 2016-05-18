/*
  This is solution for problem 33 (Digit cancelling fractions) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 18th, 2016
 */

#include <cstdio>
#include <ctime>

int GCD(const int& N, const int& D) {
	if (D == 0)
		return N;
	else
		return GCD(D, N % D);
}

bool is_cancelling_fractions(const int& num, const int& den) {
	int N[2] = { num / 10, num % 10 };
	int D[2] = { den / 10, den % 10 };

	// This will eleminate the trivial ones.
	if (N[0] == 0 || N[1] == 0 || D[0] == 0 || D[1] == 0) return false;

	if (N[0] == D[0])
		return num / static_cast<double>(den) == N[1] / static_cast<double>(D[1]);

	if (N[0] == D[1])
		return num / static_cast<double>(den) == N[1] / static_cast<double>(D[0]);


	if (N[1] == D[0])
		return num / static_cast<double>(den) == N[0] / static_cast<double>(D[1]);

	if (N[1] == D[1])
		return num / static_cast<double>(den) == N[0] / static_cast<double>(D[0]);

	return false;
}

void digit_cancelling_fractions() {
	int num_product = 1;
	int den_product = 1;
	for (int N = 10; N < 100; ++N) {
		for (int D = N + 1; D < 100; ++D) {
			if (is_cancelling_fractions(N, D)) {
				num_product *= N;
				den_product *= D;
			}
		}
	}

	printf("The GCD value of denominator == [%d]\n", den_product / GCD(num_product, den_product));
}

int main() {
	std::clock_t start = clock();
	digit_cancelling_fractions();
	printf("Execution time == [%.8f] second\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

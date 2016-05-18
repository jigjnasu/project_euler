#include <cstdio>
#include <ctime>

int gcd(const int& N, const int& D) {
	if (D == 0) return N;
	else return gcd(D, N % D);
}

bool is_digit_cancelling_fractions(const int& N, const int& D) {
	if (N == D) return false;

	int NUM[2] = { N / 10, N % 10 };
	int DEN[2] = { D / 10, D % 10 };

	// This will eleminate the trivial ones.
	if (NUM[0] == 0 || NUM[1] == 0 || DEN[0] == 0 || DEN[1] == 0) return false;

	if (NUM[0] == DEN[0])
		if ((N / static_cast<double>(D)) == NUM[1] / static_cast<double>(DEN[1])) return true;

	if (NUM[0] == DEN[1])
		if ((N / static_cast<double>(D)) == NUM[1] / static_cast<double>(DEN[0])) return true;


	if (NUM[1] == DEN[0])
		if ((N / static_cast<double>(D)) == NUM[0] / static_cast<double>(DEN[1])) return true;

	if (NUM[1] == DEN[1])
		if ((N / static_cast<double>(D)) == NUM[0] / static_cast<double>(DEN[0])) return true;

	return false;
}

int main() {
	std::clock_t start = clock();
	int numerator = 1;
	int denominator = 1;
	for (int N = 10; N <= 99; ++N) {
		for (int D = N; D <= 99; ++D) {
			if (is_digit_cancelling_fractions(N, D)) {
				printf("[%d] / [%d]\n", N, D);
				numerator *= N;
				denominator *= D;
			}
		}
	}

	printf("%d\n", denominator / gcd(numerator, denominator));
	std::clock_t end = clock();
	printf("Execution time == [%.4f]\n", static_cast<double>(end - start) / CLOCKS_PER_SEC);
}

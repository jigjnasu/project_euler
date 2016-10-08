/*
  This is solution for problem 45 (Triangular, pentagonal, and hexagonal) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
 */

#include <cstdio>
#include <cmath>
#include <ctime>

bool is_pentagonal(const double& N) {
	const double index = (1 + std::sqrt(24 * N + 1)) / 6;
	if (index - static_cast<int>(index) == 0.0)
		return true;

	return false;
}

double hexagonal_number(const double& N) {
	return (2 * N * N) - N;
}

void next_triangle_pentagonal_hexagonal_number() {
	int counter = 0;
	double i = 2;
	while (1) {
		const double number = hexagonal_number(i++);

		if (is_pentagonal(number)) {
			printf("------------------------------------------------------------------\n");
			printf("Triangle, Pentagonal and Hexagonal Number == [%10.8lf]\n", number);
			printf("-----------------------------------------------------------------\n");
			++counter;
			if (counter == 2)
				break;
		}
	}
}


int main() {
	std::clock_t start = clock();
	next_triangle_pentagonal_hexagonal_number();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

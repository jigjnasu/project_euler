#include "common/PermutationGenerator.h"
#include <cstdio>
#include <ctime>
#include <cmath>

bool is_prime(const int& N) {
	for (int i = 2; i <= std::sqrt(N); ++i)
		if (N % i == 0)
			return false;
	return true;
}

int main() {
	std::clock_t start = clock();
	PROJECT_EULER::COMMON::PermutationGenerator<int> generator(7, false);
	generator.Generate();

	std::vector<int> permutations;
	generator.Result(permutations);

	int largest_prime_number = 0;
	for (std::size_t i = 0; i < permutations.size(); ++i)
		if (is_prime(permutations[i]))
			if (permutations[i] > largest_prime_number)
				largest_prime_number = permutations[i];

	printf("largest pan digital number == [%d]\n", largest_prime_number);
	printf("Execution time == [%f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

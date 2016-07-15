/*
  This is solution for problem 52 (Cubic Permutations) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 13th, 2016
 */

#include "common/Common.h"
#include "common/PermutationGenerator.h"
#include <cstdio>
#include <cmath>
#include <string>
#include <ctime>
#include <algorithm>

bool is_cube_root(const double& number) {
	const double cube_root = std::pow(number, 1 / 3.);
	bool result = (cube_root - static_cast<int>(cube_root) == 0.00f) ? true : false;

	if (56623104 == number || 66430125 == number) {
		printf("number == [%f]\n", number);
		if ((cube_root * cube_root * cube_root) == number)
			printf("it is a perfect cube\n");
		else
			printf("it is not a perfect cube\n");
	}

	return result;
}

int number_of_cubic_permutations(std::string number) {
	std::vector<std::string> permutations;
	std::sort(number.begin(), number.end());
	PROJECT_EULER::COMMON::PermutationGenerator<double> generator(number);
	PROJECT_EULER::COMMON::Common<double> common;
	generator.Generate();
	generator.Result(permutations);
	
	int counter = 0;
	for (std::size_t i = 0; i < permutations.size(); ++i) {
		std::string data = permutations[i];
		if (is_cube_root(common.ToNumber(permutations[i])))
			++counter;
	}

	return counter;
}

int main() {
	std::clock_t start = clock();
	PROJECT_EULER::COMMON::Common<int> common;

	const int number_count = 2;

	const double number = 345 * 345 * 345;
	printf("------------------------------------------------------------\n");
	printf("[%.0f] has exact [%d] cubic permurations\n", number, number_of_cubic_permutations(common.ToString(number)));
	printf("------------------------------------------------------------\n");

	printf("Execution time == [%f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

#include "common/Integer.h"
#include <cstdio>
#include <ctime>

int main() {
	std::clock_t start = clock();

	PROJECT_EULER::COMMON::Integer<int> number(100);
	for (int i = 99; i >= 2; --i)
		number *= i;

	int sum = 0;
	const std::vector<int> num = number.GetData();
	for (std::size_t i = 0; i < num.size(); ++i)
		sum += num[i];

	printf("Sum of digits of 100! == [%d]\n", sum);
	
	printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	
	return 0;
}

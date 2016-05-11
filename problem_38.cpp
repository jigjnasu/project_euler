#include "common/QuickSort.h"
#include <cstdio>
#include <ctime>

bool is_pandigital(std::string number) {
	printf("number == [%s]\n", number.c_str());
	if (number.size() != 9)
		return false;

	PROJECT_EULER::COMMON::QuickSort<char> sort;
	sort.Sort(number);

	printf("number == [%s]\n", number.c_str());

	for (std::size_t i = 0; i < 10; ++i) {
		if (number[i] != '0' + i + 1) {
			printf("[%d] <---> [%d]\n", number[i], '0' + i + 1);
			return false;
		}
	}

	return true;
}

int main() {
	std::clock_t start = clock();
	printf("%d\n", is_pandigital("876934512"));
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	return 0;
}

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
	
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
    return 0;
}

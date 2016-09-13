#include "common/Integer.h"
#include <cstdio>
#include <ctime>

int main() {
    std::clock_t start = clock();

    Integer number(100);
    for (int i = 99; i >= 2; --i)
	number *= i;

    int sum = 0;
    std::string num = number.GetReverse();
    for (std::size_t i = 0; i < num.size(); ++i)
	sum += num[i] - '0';

    printf("Sum of digits of 100! == [%d]\n", sum);
	
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
    return 0;
}

#include <cstdio>
#include <vector>
#include <ctime>

void divisors_numbers(const unsigned long long int& number) {
	int count = 2;
	printf("1 ");
	for (int i = 2; i <= number / 2; ++i)
		if (number % i == 0)
			//++count;
			printf("%d ", i);
	printf("%d\n", number);
	
	//return count;
}

#if 0
void triangular_number(const int& divisors) {
	int iterator = 1;
	unsigned long long int number = 0;
	while (1) {
		number += iterator;
		if (divisors_numbers(number) > divisors) {
			printf("number == [%llu]\n", number);
			break;
		}
		++iterator;
	}
}
#endif

int main() {
	std::clock_t start = clock();
	//triangular_number(400);
	divisors_numbers(28);
	divisors_numbers(56);
	printf("Execution time == [%.2f]\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
	return 0;
}

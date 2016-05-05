#include <cstdio>
#include <ctime>

const int MAX = 9999;

int divisors_sum(const int& N) {
	int sum = 1;
	for (int i = 2; i <= N / 2; ++i)
		if (N % i == 0)
			sum += i;

	return sum;
}

int ammicable_numbers() {
	int sum = 0;
	int numbers_sum = 0;
	int dictionary[MAX] = { 0 };

	for (int i = 1; i <= MAX; ++i) {
		if (dictionary[i - 1] == 0)
			sum = divisors_sum(i);
		if (sum < MAX) {
			dictionary[i - 1] = sum;

			if (dictionary[sum - 1] == 0) {
				int temp = divisors_sum(sum);
				if (temp < MAX) {
					dictionary[sum - 1] = temp;

					if (i == temp)
						numbers_sum += i + sum;
				}
			}
		}
	}

	
	return numbers_sum;
}

int main() {
	std::clock_t start = clock();
	printf("Sum of all amicable numbers below 1000 == [%d]\n", ammicable_numbers());
	printf("Execution time == [%.2f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

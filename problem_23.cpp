#include <cstdio>
#include <vector>
#include <ctime>

const int MAX = 28123;


int sum_of_divisors(const int& N) {
	int sum = 0;
	for (int i = 1; i <= N / 2; ++i)
		if (N % i == 0)
			sum += i;
	return sum;
}

void get_all_abundant_numbers(std::vector<int>& abundant_numbers) {
	for (int i = 1; i < MAX; ++i) {
		if (i < sum_of_divisors(i))
			abundant_numbers.push_back(i);
	}
}

void get_all_positive_numbers(std::vector<int>& all_numbers) {
	for (int i = 1; i < MAX; ++i)
		all_numbers.push_back(i);
}

void sum_of_positive_integers() {
	std::vector<int> all;
	std::vector<int> abundants;
	
	get_all_positive_numbers(all);
	get_all_abundant_numbers(abundants);

	for (std::size_t i = 0; i < abundants.size(); ++i) {
		for (std::size_t j = i; j < abundants.size(); ++j) {
			const int index = abundants[i] + abundants[j];
			if (index < MAX)
				all[index - 1] = 0;
		}
	}

	int sum = 0;
	for (std::size_t i = 0; i < all.size(); ++i)
		sum += all[i];

	printf("Sum of all positive integers which cannot be written as sum of two abundant numbers == [%d]\n", sum);
}

int main() {
	std::clock_t start = clock();
	sum_of_positive_integers();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

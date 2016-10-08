/*
  This is solution for problem 32 (Pandigital products) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 18th, 2016
 */

#include <cstdio>
#include <set>
#include <ctime>

bool is_pandigital(int A, int B, int C) {
	int array[9] = {0};

	while (A) {
		const int value = A % 10;
		if (array[value - 1])
			return false;
		else
			array[value - 1] = 1;
		A /= 10;
	}

	while (B) {
		const int value = B % 10;
		if (array[value - 1])
			return false;
		else
			array[value - 1] = 1;
		B /= 10;
	}

	while (C) {
		const int value = C % 10;
		if (array[value - 1])
			return false;
		else
			array[value - 1] = 1;
		C /= 10;		
	}

	for (int i = 0; i < 9; ++i)
		if (array[i] == 0)
			return false;

	return true;
}

void pandigital_product() {
	std::set<int> products;
	for (int i = 1; i < 100; ++i) {
		for (int j = 100; j < 2000; ++j) {
			if (is_pandigital(i, j, i * j))
				products.insert(i * j);
		}
	}

	int product_sum = 0;
	for (std::set<int>::const_iterator it = products.begin(); it != products.end(); ++it)
		product_sum += *it;

	printf("Product sum of all pandigital numbers == [%d]\n", product_sum);
}

int main() {
	std::clock_t start = clock();
	pandigital_product();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

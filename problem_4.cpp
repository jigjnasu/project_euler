#include <cstdio>
#include <string>
#include <ctime>
#include <sstream>

bool is_palindrome(const std::string& S) {
	int i = 0;
	int j = S.size() - 1;
	while (i < j)
		if (S[i++] != S[j--])
			return false;

	return true;
}

void find_largest_product_palindrome() {
	int largest = 0;
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			int product = i * j;
			std::ostringstream oss;
			oss << product;
			if (is_palindrome(oss.str()))
				if (product > largest)
					largest = product;
		}
	}

	printf("largest palindrome product of 3 digit == [%d]\n", largest);
}

int main() {
	std::clock_t start = clock();
	find_largest_product_palindrome();

	printf("Exection time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);

	return 0;
}

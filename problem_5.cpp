#include <cstdio>
#include <ctime>

void smallest_multiple(const int& max) {
	unsigned long long int number = max + 1;
	while (1) {
		bool is_quit = true;
		for (int i = 2; i <= max; ++i) {
			if (number % i) {
				is_quit = false;
			}
		}

		if (is_quit) {
			printf("smallest mulitple == [%llu]\n", number);
			break;
		}
		++number;
	}
}

int main() {
	std::clock_t start = clock();
	smallest_multiple(20);

	printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);

	return 0;
}

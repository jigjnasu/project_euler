#include <cstdio>
#include <vector>
#include <ctime>
#include <cmath>

typedef u_long unsigned long long int;

u_long pentagon_number(const int& N) {
	return (N * ((3 * N) - 1)) >> 1;
}

void sum_diff() {
	u_long min_number = 0;
	for (std::size_t i = 0; i < numbers.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < numbers.size(); ++j) {
			
		}
	}
}


int main() {
	std::clock_t start = clock();
	sum_diff();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

#include <cstdio>
#include <ctime>

int main() {
	std::clock_t start = clock();

	printf("Execution time == [%f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	return 0;
}

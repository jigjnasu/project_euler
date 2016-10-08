#include <cstdio>

int main() {
	int n = 100;
	int S1 = (n * (n + 1)) / 2;
	int S2 = (n * (n + 1) * ((2 * n) + 1)) / 6;

	printf("%d\n", (S1 * S1) - S2);
	return 0;
}

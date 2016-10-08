#include <cstdio>

void special_triplet() {
	for (int a = 1; a < 1000 / 2; ++a) {
		for (int b = 1; b < 1000 / 2; ++b) {
			const int c = 1000 - (a + b);
			if (((a * a) + (b * b)) == (c * c)) {
				printf("product == [%d]\n", a * b * c);
				return;
			}
		}
	}
}

int main() {
	special_triplet();

	return 0;
}

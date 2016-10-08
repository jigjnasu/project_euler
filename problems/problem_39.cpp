/*
  This is solution for problem 39 (Integer right triangles) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
 */

#include <cstdio>
#include <ctime>

void integer_right_triangles() {
	int max_p = 0;
	int max_count = 0;
	for (int p = 1; p <= 1000; ++p) {
		int counter = 0;
		for (int a = 1; a <= p / 3; ++a) {
			for (int b = 1; b <= p / 2; ++b) {
				const int c = p - (a + b);
				if ((c * c) == (a * a) + (b * b))
					++counter;
			}
		}
		if (counter > max_count) {
			max_p = p;
			max_count = counter;
		}
	}

	printf("Max p with right angled triangles == [%d]\n", max_p);
}

int main() {
	std::clock_t start = clock();
	integer_right_triangles();
	printf("Execution time == [%.6f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}

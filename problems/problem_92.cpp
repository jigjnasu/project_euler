/*
  This is solution for problem 92 (Square digit chains) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 2nd, 2016
 */

#include <cstdio>
#include <ctime>

int get_square_digit(int N) {
	int square_sum = 0;
	while (N) {
		const int T = N % 10;
		square_sum += (T * T);
		N /= 10;
	}

	return square_sum;
}

void square_digit_chains() {
	const int MAX = 10000000;
	const int size = 10000;
	int dictionary[size] = { 0 };
	
	int counter = 0;
	for (int i = 1; i < MAX; ++i) {
		int number = i;
		while (1) {
			number = get_square_digit(number);

			if (dictionary[number] == 1)
				break;
			if (dictionary[number] == 89) {
				++counter;
				break;
			}

			if (number == 1) {
				if (i < size)
					dictionary[i] = 1;
				break;
			}

			if (number == 89) {
				if (i < size)
					dictionary[i] = 89;
				++counter;
				break;
			}							   
		}
	}

	printf("-----------------------------------------------------------------\n");
	printf("Number of Square Digit Chains ending at 89 == [%d]\n", counter);
	printf("-----------------------------------------------------------------\n");
}

int main() {
	std::clock_t start = clock();
	square_digit_chains();
	printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	
	return 0;
}

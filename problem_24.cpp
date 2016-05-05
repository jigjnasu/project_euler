#include <cstdio>
#include <iostream>
#include <ctime>

void swap(int& A, int& B) {
	int T = A;
	A = B;
	B = T;
}

template <std::size_t N>
void get_next(int (&A)[N]) {
	int i = N -1;
	while (A[i - 1] >= A[i])
		--i;

	int j = N;
	while (A[j -1] <= A[i -1])
		--j;

	swap(A[i - 1], A[j - 1]);

	++i;
	j = N;
	while (i < j) {
		swap(A[i - 1], A[j - 1]);
		++i;
		--j;
	}
}

template <std::size_t N>
void print(const int (&V)[N]) {
	for (std::size_t i = 0; i < N; ++i)
		printf("%d", V[i]);
	printf("\n");
}

void permutation_generator() {
	int V[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for (int i = 1; i < 1000000 ; ++i) {
		get_next<10>(V);
	}
	print(V);
}

int main() {
	std::clock_t start = clock();
	permutation_generator();
	std::clock_t end = clock();
	printf("Execution time == [%.8f] seconds\n", (end - start) / static_cast<double>(CLOCKS_PER_SEC));

	return 0;
}

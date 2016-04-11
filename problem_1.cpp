#include <cstdio>

typedef unsigned long long int ul_int;

ul_int get_sum(int i, ul_int N) {
	ul_int a = i;
	ul_int l = (N % i == 0) ? N : N - (N % i);
	ul_int k = l / a;

	return (k * (a + l)) >> 1;
}

int main() {
	const int N = 999;
	printf("%llu\n", (get_sum(3, N) + get_sum(5, N)) - get_sum(15, N));

	return 0;
}

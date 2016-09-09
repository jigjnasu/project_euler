#include <cstdio>

int main() {
    int S = 0;
    int A = 1;
    int B = 2;
    S += 2;

    while (1) {
	const int C = A + B;
	A = B;
	B = C;
	if (C > 4000000)
	    break;
	if (C % 2 == 0)
	    S += C;
    }

    printf("sum == [%d]\n", S);

    return 0;
}

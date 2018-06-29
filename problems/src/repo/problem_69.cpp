/*
  Problem 69, mathematical solution with minimum time complexity.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Dec 5th, 2016
 */

#include <cstdio>
#include <ctime>
#include <cmath>

bool is_prime(int n) {
    for (int i = 2; i <= std::sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int maximum_factor(int n) {
    int product = 1;
    int iter = 2;
    while (product <= n) {
        if (is_prime(iter))
            product *= iter;
        ++iter;
    }

    return product / (iter - 1);
}

int main() {
    std::clock_t start = clock();
    const int n = 1000000;
    printf("Maximum factor between 2 ..... %d == [%d]\n", n, maximum_factor(n));
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    return 0;
}

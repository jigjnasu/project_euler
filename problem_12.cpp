#include <cstdio>
#include <ctime>
#include <cmath>

int divisor_count(const unsigned long long int& N) {
  int counter = 0;
  const int value = std::sqrt(static_cast<double>(N));
  for (int i = 1; i <= value; ++i)
    if (N % i == 0)
      counter += 2;

  if (value * value == N)
    --counter;

  return counter;
}

int main() {
  std::clock_t start = clock();
  unsigned long long int number = 0;
  int iter = 1;
  while (1) {
    number += iter;
    ++iter;
    if (divisor_count(number) > 500) {
      printf("%llu\n", number);
      break;
    }
  }

  printf("Execution time == [%.2f]\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
  return 0;
}

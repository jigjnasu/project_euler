#include <cstdio>
#include <ctime>
#include <map>

int collatz_sequence(unsigned long long int N) {
  int counter = 1;
  while (N != 1) {
    ++counter;
    if (N % 2)
      N = (3 * N) + 1;
    else
      N /= 2;
  }

  return counter;
}

int main() {
  std::clock_t start = clock();
  unsigned long long int number = 0;
  int longest_chain = 0;
  for (unsigned long long int i = 2; i < 1000000; ++i) {
    int sequence = collatz_sequence(i);
    if (sequence > longest_chain) {
      longest_chain = sequence;
      number = i;
    }
  }

  printf("[%llu] has longest collatz sequence of [%d] elements\n", number, longest_chain);
  printf("Execution time == [%.2f] seconds\n", (clock() - static_cast<double>(start)) / CLOCKS_PER_SEC);
  return 0;
}

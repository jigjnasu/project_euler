#include "problem_12.h"
#include <cstdio>
#include <cmath>

namespace pp = project_euler::problems;

pp::Problem_12::Problem_12() {}

pp::Problem_12::~Problem_12() {}

void pp::Problem_12::max_divisible_triangular_number() const {
  int iter = 1;
  u_l number = 0;

  while (1) {
    number += iter;
    ++iter;

    const int count = m_count_divisor(number);
    if (count > 500) {
        printf("Triangular Number [%llu] with divisble count == [%d]\n", number, count);
      break;
    }
  }
}

int pp::Problem_12::m_count_divisor(const u_l& n) const {
  int counter = 0;
  const u_l value = std::sqrt(static_cast<int>(n));
  for (u_l i = 1; i <= value; ++i)
    if (n % i == 0)
      counter += 2;

  if (value * value == n)
    --counter;

  return counter;
}

/*
  This is the solution for Problem 72, (Counting Fractions) from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 3rd, 2016
 */

#include "Problem_72.h"
#include <vector>

namespace pp = project_euler::problems;

pp::Problem_72::Problem_72() {}

pp::Problem_72::~Problem_72() {}

// This function is using Euler's totient function
// And Sieve Eratosthenes function to generate prime numbers.
long pp::Problem_72::counting_fractions(const int& n) const {
    long fractions_count = 0;

    std::vector<int> phi;
    for (int i = 0; i <= n; ++i)
        phi.push_back(i);

    for (std::size_t i = 2; i < phi.size(); ++i) {
        if (phi[i] == static_cast<int>(i))
            for (std::size_t j = i; j < phi.size(); j += i)
                phi[j] = (phi[j] * (i - 1)) / i;
        fractions_count += phi[i];
    }

    return fractions_count;
}

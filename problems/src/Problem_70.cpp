/*
  This is the solution for Problem 70, (Totient Permutations) from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 9th, 2016
 */

/*
  Algorithm explained.
  1.. Calculate all the phi from 2 .... limit with the help of Sieve of Eratosthenes algorithm
  2.. Take a brute force approach to find the permutation of n and phi(n)
  3.. Just compare it with the minimum ratio of n / phi(n)
  4.. Save the min value
 */

#include "Problem_70.h"
#include "Maths.h"
#include <vector>
#include <cstdio>

const int limit = 10000000;

namespace pp = project_euler::problems;

pp::Problem_70::Problem_70() {}

pp::Problem_70::~Problem_70() {}

void pp::Problem_70::totient_permutation() const {
    utility::maths::Maths<std::size_t> maths;
    const std::vector<std::size_t> phi = maths.phi_all(limit);

    double min = limit;
    std::size_t n = 0;
    for (std::size_t i = 2; i < phi.size(); ++i) {
        if (m_is_permutation(i, phi[i])) {
            const double ratio = i / static_cast<double>(phi[i]);
            if (ratio < min) {
                min = ratio;
                n = i;
            }
        }
    }

    printf("-------------------------------------------------\n");
    printf("n == [%ld] || phi[%ld] == [%ld] || ratio == [%.8f]\n",
           n, n, phi[n], min);
    printf("-------------------------------------------------\n");    
}

bool pp::Problem_70::m_is_permutation(std::size_t a, std::size_t b) const {
    const int n = 10;
    // 0 ... 9 frequency
    std::size_t frequency_a[n] = {0};
    std::size_t frequency_b[n] = {0};

    while (a) {
        ++frequency_a[a % 10];
        a /= 10;
    }

    while (b) {
        ++frequency_b[b % 10];
        b /= 10;
    }

    for (std::size_t i = 0; i < n; ++i)
        if (frequency_a[i] != frequency_b[i])
            return false;
    return true;
}

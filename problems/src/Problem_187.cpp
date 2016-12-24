/*
  This is the solution for Problem 187, (Semi Primes) from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 6th, 2016
 */

#include "Problem_187.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_187::Problem_187() {}

pp::Problem_187::~Problem_187() {}

int pp::Problem_187::semi_primes(std::size_t n) const {
    utility::maths::Maths<std::size_t> maths;
    const std::vector<std::size_t> prime_numbers = maths.prime_numbers(n / 2);

    int semi_prime_counter = m_square_factors(n, prime_numbers);
    semi_prime_counter += m_2_factors(n, prime_numbers);
    
    return semi_prime_counter;
}

int pp::Problem_187::m_square_factors(std::size_t n, const std::vector<std::size_t>& prime_numbers) const {
    int factors = 0;
    for (std::size_t i = 0; (prime_numbers[i] * prime_numbers[i]) <= n; ++i)
        ++factors;
    
    return factors;
}

int pp::Problem_187::m_2_factors(std::size_t n, const std::vector<std::size_t>& prime_numbers) const {
    int factors = prime_numbers.size() - 1;

    for (std::size_t i = 1; i < prime_numbers.size(); ++i) {
        if ((prime_numbers[i] * prime_numbers[i + 1]) <= n) {
            for (std::size_t j = i + 1;
                 (prime_numbers[i] * prime_numbers[j]) <= n;
                 ++j)
                ++factors;
        } else {
            return factors;
        }
    }

    return factors;
}

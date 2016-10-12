/*
  This is solution for problem 46 (Goldbach's other conjecture) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "Problem_47.h"
#include "Maths.h"
#include <cstdio>
#include <algorithm>

namespace pp = project_euler::problems;

pp::Problem_47::Problem_47() {}

pp::Problem_47::~Problem_47() {}

void pp::Problem_47::distinct_prime_factors() const {
    utility::maths::Maths<int> math;
    std::vector<int> factor_a;
    std::vector<int> factor_b;
    std::vector<int> factor_c;
    std::vector<int> prime_numbers;
	
    int i = 2;
    for (int i = 2; i <= 4; ++i)
        if (math.is_prime(i))
            prime_numbers.push_back(i);
    
    factor_a = m_factors(i, prime_numbers);
    factor_b = m_factors(i + 1, prime_numbers);
    factor_c = m_factors(i + 2, prime_numbers);
    
    i = i + 3;
    while (1) {
        std::vector<int> factor_d;
		
        if (math.is_prime(i))
            prime_numbers.push_back(i);

        factor_d = m_factors(i, prime_numbers);

        std::vector<int> factors;
        factors.insert(factors.end(), factor_a.begin(), factor_a.end());
        factors.insert(factors.end(), factor_b.begin(), factor_b.end());
        factors.insert(factors.end(), factor_c.begin(), factor_c.end());
        factors.insert(factors.end(), factor_d.begin(), factor_d.end());

        if (m_is_distinct_factor(factors)) {
            m_print(i - 3, factor_a);
            m_print(i - 2, factor_b);
            m_print(i - 1, factor_c);
            m_print(i, factor_d);
            break;
        }
        
        factor_a = factor_b;
        factor_b = factor_c;
        factor_c = factor_d;
		
        ++i;
    }
}

std::vector<int> pp::Problem_47::m_factors(int n, const std::vector<int>& prime_numbers) const {
    utility::maths::Maths<int> math;
    std::vector<int> factors;

    if (prime_numbers.size()) {
        int number = n;
        int prime_iter = 0;
        while (number != 1 && prime_numbers[prime_iter] <= n / 2) {
            int factor = 1;
            while (number % prime_numbers[prime_iter] == 0) {
                factor *= prime_numbers[prime_iter];
                number /= prime_numbers[prime_iter];
            }

            if (factor != 1)
                factors.push_back(factor);
            ++prime_iter;
        }
    }

    return factors;
}

bool pp::Problem_47::m_is_distinct_factor(const std::vector<int>& factors) const {
    if (factors.size() != 16)
        return false;

    for (std::size_t i = 0; i < factors.size() - 1; ++i) {
        for (std::size_t j = i + 1; j < factors.size(); ++j) {
            if (factors[i] == factors[j])
                return false;
        }
    }

    return true;    
}

void pp::Problem_47::m_print(int n, const std::vector<int>& factors) const {
    printf("[%d] ==== ", n);
    for (std::size_t i = 0; i < factors.size(); ++i)
        printf("[%8d] ", factors[i]);
    printf("\n");
}

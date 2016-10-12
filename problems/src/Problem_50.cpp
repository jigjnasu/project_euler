/*
  This is solution for problem 50 (Consecutive prime sum) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
*/

#include "Problem_50.h"
#include "Maths.h"
#include <cstdio>
#include <ctime>
#include <cmath>
#include <vector>

const int MILLION = 1000000;

namespace pp = project_euler::problems;

pp::Problem_50::Problem_50() {}

pp::Problem_50::~Problem_50() {}

void pp::Problem_50::consecutive_prime_sum() const {
    m_largest_sum(m_prime_sums());
}

std::vector<int> pp::Problem_50::m_prime_sums() const {
    utility::maths::Maths<int> math;
    std::vector<int> prime_sums;
    prime_sums.push_back(2);
    int last_sum = 2;
    int iter = 3;
    
    while (1) {
        if (math.is_prime(iter)) {
            if (iter + last_sum > MILLION)
                break;
            prime_sums.push_back(iter + last_sum);
            last_sum += iter;
        }
        ++iter;
    }

    return prime_sums;
}

void pp::Problem_50::m_largest_sum(const std::vector<int>& prime_sums) const {
    utility::maths::Maths<int> math;    
    int longest_chain = 0;
    int largest_number = 0;
    
    for (int i = prime_sums.size() - 1; i > 0; --i) {
        int chain = 0;

        for (int j = 0; j < i; ++j) {
            if (math.is_prime(prime_sums[i] - prime_sums[j])) {
                chain = i - j;
                if (chain > longest_chain) {
                    longest_chain = chain;
                    largest_number = prime_sums[i] - prime_sums[j];
                }
            }
        }
    }

    printf("-----------------------------------------------------------\n");
    printf("Largest consecutive prime number == [%d]\n", largest_number);
    printf("-----------------------------------------------------------\n");    
}

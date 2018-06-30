/*
  This is solution for problem 46 (Goldbach's other conjecture) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "problem_46.h"
#include "maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_46::Problem_46() {}

pp::Problem_46::~Problem_46() {}

void pp::Problem_46::goldbach_conjecture() const {
    std::vector<int> prime_numbers;
    utility::maths::Maths<int> math;

    int number = 2;
    while (1) {
        if (math.is_prime(number)) {
            prime_numbers.push_back(number);
        } else {
            if (number % 2) {
                if (!m_is_goldbach_conjecture(number, prime_numbers)) {
                    printf("Goldbach's Other Conjucture has been broken at [%d]\n", number);
                    break;
                }
            }
        }
        ++number;
    }
}

bool pp::Problem_46::m_is_goldbach_conjecture(int n, const std::vector<int>& prime_numbers) const {
    int prime_iter = 0;
    while (prime_numbers[prime_iter] < n) {
        int power = 1;
        while (1) {
            const int number = prime_numbers[prime_iter] + (2 * power * power);
            if (number == n)
                return true;
            if (number > n)
                break;
            ++power;
        }

        ++prime_iter;
    }

    return false;
}

/*
  This is solution for problem 27 (Quadratic primes) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "Problem_27.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_27::Problem_27() {}

pp::Problem_27::~Problem_27() {}

void pp::Problem_27::quadratic_primes() const {
    utility::maths::Maths<int> maths;
    int largest_a = 0;
    int largest_b = 0;
    int largest_n = 0;
    for (int a = -1000; a <= 1000; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int n = 0;
            while (maths.is_prime(m_quadratic_prime(a, b, n)))
                ++n;

            if (n > largest_n) {
                largest_a = a;
                largest_b = b;
                largest_n = n;
            }
        }
    }

    printf("product of a and b == [%d]\n", largest_a * largest_b);    
}

int pp::Problem_27::m_quadratic_prime(int a, int b, int n) const {
    return std::abs((n * n) + (a * n) + b);    
}

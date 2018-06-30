/*
  Solution for Problem 63(Powerful digit counts) from ProjectEuler.net
  Author: Rakesh Kumar cpp.rakesh(at)gmail.com
  Date: 7th, Jan 2017
 */

#include "problem_63.h"
#include "integer.h"
#include "maths.h"
#include <cstdio>
#include <cmath>

/*
  Maths explanasion behind this problem
 */

namespace pp = project_euler::problems;

pp::Problem_63::Problem_63() {}

pp::Problem_63::~Problem_63() {}

void pp::Problem_63::powerful_digit_counts() const {
    int start = 0;
    double n = 1;
    int count = 0;
    while (start < 10) {
        start = std::ceil(std::pow(10, (n - 1) / n));
        count += 10 - start;
        ++n;
    }

    printf("---------------------------------------------\n");
    printf("Total number of powerful digit counts == [%d]\n", count);
    printf("---------------------------------------------\n");

    printf("Let's print all the numbers\n");
    m_print_numbers();
}

void pp::Problem_63::m_print_numbers() const {
    utility::maths::Maths<utility::integer::Integer> maths;
    std::size_t exp = 1;
    int count = 1;
    while (exp < 22) {
        utility::integer::Integer n(1);
        while (1) {
            const utility::integer::Integer number = maths.power(n, exp);
            if (number.size() == exp) {
                printf("[%3d] --> [%s] ^ [%lu] == [%s]\n",
                       count, n.get().c_str(), exp, number.get().c_str());
                ++count;
            } else if (number.size() > exp){
                break;
            }

            n += 1;
        }
        ++exp;
    }
}

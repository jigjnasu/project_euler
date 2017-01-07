/*
  Solution for Problem 63(Powerful digit counts) from ProjectEuler.net
  Author: Rakesh Kumar cpp.rakesh(at)gmail.com
  Date: 7th, Jan 2017
 */

#include "Problem_63.h"
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
}

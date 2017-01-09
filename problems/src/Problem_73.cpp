/*
  Solution for Problem 73(Counting fractions in a range) from Project Euler
  The solution is based on Farey sequence
  Algorithm is designed on https://en.wikipedia.org/wiki/Farey_sequence
  
  Rakesh Kumar, cpp.rakesh(at)gmail.com
  Jan 9th, 2017
 */

#include "Problem_73.h"
#include <cmath>
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_73::Problem_73() {}

pp::Problem_73::~Problem_73() {}

void pp::Problem_73::counting_fractions() const {
    const int n = 12000;
    // These are the first two terms which we can calculate easily
    double a = 0;
    double b = 1;
    double c = 1;
    double d = n;

    std::size_t count = 0;
    bool should_count = false;

    while (1)
    {
        // Using recurrence relation to find the next term
        const double p = floor((n + b) / d) * c - a;
        const double q = floor((n + b) / d) * d - b;

        if (should_count == false && (p == 1 && q == 3))
            should_count = true;

        if (should_count == true && (p == 1 && q == 2))
            break;

        a = c, c = p, b = d, d = q;
        if (should_count)
            ++count;
    }

    printf("There are total [%lu] ordered fraction between 1 / 3 and 1 / 2 for n = [%d]\n", count - 1, n);
}

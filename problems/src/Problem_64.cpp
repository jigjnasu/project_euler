#include "Problem_64.h"
#include <cmath>
#include <cstdio>

/*
  This algorithm is based on Wikipedia algorithm to count continued fractions for any natural number S.

  m0    = 0
  d0    = 1
  a0    = floor [sqrt(S)]

  m n+1 = dn an - mn
  d n+1 = S - square(m n+1) / dn
  a n+1 = floor [ a0 + m n+1 / d n+1 ]

  It will terminate when aj = 2 a0

  This is the solution for problem 64, Odd Period Square Roots.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 22nd, 2016
*/

namespace pp = project_euler::problems;

pp::Problem_64::Problem_64() {}

pp::Problem_64::~Problem_64() {}

void pp::Problem_64::count_continued_fractions_periods(int n) const {
    int odd_periods = 0;
    for (int i = 2; i <= n; ++i)
        if (m_length_of_contined_fractions(i) % 2)
            ++odd_periods;

    printf("Total odd periods between 2 and %d is == [%d]\n", n, odd_periods);
}

int pp::Problem_64::m_length_of_contined_fractions(int s) const {
    const int a0 = static_cast<int>(std::sqrt(s));
    if ((a0 * a0) == s)
        return 0;
    
    int count = 0;
    int m = 0;
    int d = 1;
    int a = a0;

    while (2 * a0 != a) {
        m = (d * a) - m;
        d = (s - (m * m)) / d;
        a = (a0 + m) / d;
        ++count;
    }

    return count;    
}

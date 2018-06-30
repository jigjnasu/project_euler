/*
  Solution for Problem 71 (Ordered Fraction) from ProjectEuler.net
  Rakesh Kumar , cpp.rakesh(at)gmail.com
  Date: Jan 9th, 2017
 */

#include "problem_71.h"
#include "maths.h"
#include <cmath>
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_71::Problem_71() {}

pp::Problem_71::~Problem_71() {}

// This algorithm has been learned from wikipedia.

/*
  Idea behind this problem is getting the average of min + max(3 / 7).
  And try to find out till we have less than the 3 / 7.
 */

void pp::Problem_71::ordered_fractions() const {
    utility::maths::Maths<int> maths;
    const int n = 1000000;
    int a = 0;
    int b = 1;

    int c = 3;
    int d = 7;

    while (b + d <= n) {
        a += c;
        b += d;

        const int factor = maths.gcd(a, b);

        a /= factor;
        b /= factor;
    }

    printf("Fraction [%d] / [%d] < [3] / [7] and just smaller than this when n = 1000000\n", a, b);
}

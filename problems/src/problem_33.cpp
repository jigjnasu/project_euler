/*
  This is solution for problem 33 (Digit cancelling fractions) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 18th, 2016
*/

#include "Problem_33.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_33::Problem_33() {}

pp::Problem_33::~Problem_33() {}

void pp::Problem_33::digit_cancelling_fractions() const {
    int num_product = 1;
    int den_product = 1;
    for (int n = 10; n < 100; ++n) {
        for (int d = n + 1; d < 100; ++d) {
            if (m_is_cancelling_fractions(n, d)) {
                num_product *= n;
                den_product *= d;
            }
        }
    }

    utility::maths::Maths<int> math;
    printf("The GCD value of denominator == [%d]\n", den_product / math.gcd(num_product, den_product));    
}

bool pp::Problem_33::m_is_cancelling_fractions(int n, int d) const {
    int N[2] = { n / 10, n % 10 };
    int D[2] = { d / 10, d % 10 };

    // This will eleminate the trivial ones.
    if (N[0] == 0 || N[1] == 0 || D[0] == 0 || D[1] == 0) return false;

    if (N[0] == D[0])
        return n / static_cast<double>(d) == N[1] / static_cast<double>(D[1]);

    if (N[0] == D[1])
        return n / static_cast<double>(d) == N[1] / static_cast<double>(D[0]);


    if (N[1] == D[0])
        return n / static_cast<double>(d) == N[0] / static_cast<double>(D[1]);

    if (N[1] == D[1])
        return n / static_cast<double>(d) == N[0] / static_cast<double>(D[0]);

    return false;    
}

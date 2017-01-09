/*
  Solution for Problem 73(Counting fractions in a range) from Project Euler
  The solution is based on divide and conquer try to find out all the
  numbers between 1 / 3 and 1 / 2 with d <= 12000
  
  Rakesh Kumar, cpp.rakesh(at)gmail.com
  Jan 9th, 2017
 */

#include "Problem_73.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_73::Problem_73() : m_counter(0) {}

pp::Problem_73::~Problem_73() {}

void pp::Problem_73::counting_fractions() {
    const int a = 1;
    const int b = 3;

    const int c = 1;
    const int d = 2;

    const int n = 12000;
    
    m_counting_fractions(a, b, c, d, n);
    printf("Total ordered fractions between 1 / 3 and 1 / 2 is [%d] with d <= 12000\n", m_counter);
}

void pp::Problem_73::m_counting_fractions(int a, int b, int c, int d, int n) {
    utility::maths::Maths<int> maths;
    if (b + d <= n) {
        int p = a + c;
        int q = b + d;

        ++m_counter;
                
        const int factor = maths.gcd(p, q);

        p /= factor;
        q /= factor;

        m_counting_fractions(a, b, p, q, n);
        m_counting_fractions(p, q, c, d, n);
    }
}

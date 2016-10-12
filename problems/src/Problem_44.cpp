/*
  This is solution for problem 44 (Pentagon numbers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
*/
#include "Problem_44.h"
#include <cstdio>
#include <cmath>

namespace pp = project_euler::problems;

pp::Problem_44::Problem_44() {}

pp::Problem_44::~Problem_44() {}

void pp::Problem_44::min_difference() const {
    int p = 1;
    while (1) {
        const int a = m_pentagon_number(p);

        for (int q = p - 1; q > 0; --q) {
            const int b = m_pentagon_number(q);
            if (m_is_pentagon_number(a + b) && m_is_pentagon_number(a - b)) {
                printf("------------------------------------------------------\n");
                printf("Sum == [%d] || Difference == [%d]\n", a + b, a - b);
                printf("------------------------------------------------------\n");
                return;
            }
        }
        ++p;
    }    
}

int pp::Problem_44::m_pentagon_number(int n) const {
    return (n * ((3 * n) - 1)) / 2;    
}

bool pp::Problem_44::m_is_pentagon_number(int n) const {
    const float num = (1 + std::sqrt(24 * n + 1)) / 6;
    if (num - static_cast<int>(num) > 0.0)
        return false;
	
    return true;    
}

/*
  This is solution for problem 45 (Triangular, pentagonal, and hexagonal) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
*/

#include "problem_45.h"
#include <cstdio>
#include <cmath>

namespace pp = project_euler::problems;

pp::Problem_45::Problem_45() {}

pp::Problem_45::~Problem_45() {}

void pp::Problem_45::next_number() const {
    int counter = 0;
    double i = 2;
    while (1) {
        const double number = m_hexagonal(i++);

        if (m_is_pentagonal(number)) {
            printf("------------------------------------------------------------------\n");
            printf("Triangle, Pentagonal and Hexagonal Number == [%10.8lf]\n", number);
            printf("-----------------------------------------------------------------\n");
            ++counter;
            if (counter == 2)
                break;
        }
    }
}

bool pp::Problem_45::m_is_pentagonal(const double& n) const {
    const double index = (1 + std::sqrt(24 * n + 1)) / 6;
    if (index - static_cast<int>(index) == 0.0)
        return true;

    return false;
}

double pp::Problem_45::m_hexagonal(const double& n) const {
    return (2 * n * n) - n;
}

#include "Problem_74.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_74::Problem_74() {
    utility::maths::Maths<int> maths;
    for (int i = 0; i < 10; ++i)
        m_factorial_dictionary.push_back(maths.factorial(i));
}

pp::Problem_74::~Problem_74() {}

void pp::Problem_74::digit_factorial_chains() const {
    for (int i = 1; i < 100; ++i) {
        
    }
}

int pp::Problem_74::m_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

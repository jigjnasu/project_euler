#include "problem_34.h"
#include "maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_34::Problem_34() {}

pp::Problem_34::~Problem_34() {}

void pp::Problem_34::digit_factorials() const {
    // Pre calculations of factorials from 0 to 9
    utility::maths::Maths<int> math;
    std::vector<int> factorials;

    for (int i = 0; i < 10; ++i)
        factorials.push_back(math.factorial(i));

    int sum = 0;
    for (int i = 3; i < 10000000; ++i)
        if (m_is_equal(i, factorials))
            sum += i;

    printf("Sum of digit factorials == [%d]\n", sum);
}

bool pp::Problem_34::m_is_equal(int n, const std::vector<int>& factorials) const {
    int sum = 0;
    int temp = n;
    while (temp) {
        sum += factorials[temp % 10];
        temp /= 10;
    }

    return sum == n;
}

#include "problem_30.h"
#include "maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_30::Problem_30() {}

pp::Problem_30::~Problem_30() {}

void pp::Problem_30::digit_fifth_power() const {
    int sum = 0;
    for (int i = 2; i <= 1000000; ++i)
        if (m_is_digit_fifth_power(i))
            sum += i;
    printf("Sum of digit of fifth powers == [%d]\n", sum);
}

bool pp::Problem_30::m_is_digit_fifth_power(int n) const {
    utility::maths::Maths<int> maths;
    int temp = n;
    int sum = 0;

    while (temp) {
        int value = temp % 10;
        sum += maths.power(value, 5);
        temp /= 10;
    }

    if (n != sum)
        return false;

    return true;
}

#include "Problem_21.h"
#include <cstdio>

namespace pp = project_euler::problems;

const int MAX = 9999;

pp::Problem_21::Problem_21() {}

pp::Problem_21::~Problem_21() {}

void pp::Problem_21::sum_of_amicable_numbers() const {
    int sum = 0;
    int numbers_sum = 0;
    int dictionary[MAX] = { 0 };

    for (int i = 1; i <= MAX; ++i) {
        if (dictionary[i - 1] == 0)
            sum = m_divisors_sum(i);
        if (sum < MAX) {
            dictionary[i - 1] = sum;

            if (dictionary[sum - 1] == 0) {
                const int temp = m_divisors_sum(sum);
                if (temp < MAX) {
                    dictionary[sum - 1] = temp;

                    if (i == temp)
                        numbers_sum += i + sum;
                }
            }
        }
    }

    printf("Sum of all amicable numbers below 10000 == [%d]\n", numbers_sum);
}

int pp::Problem_21::m_divisors_sum(int n) const {
    int sum = 1;
    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0)
            sum += i;

    return sum;
}

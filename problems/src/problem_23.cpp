#include "Problem_23.h"
#include <cstdio>

const int MAX = 28123;

namespace pp = project_euler::problems;

pp::Problem_23::Problem_23() {}

pp::Problem_23::~Problem_23() {}

void pp::Problem_23::non_abundant_sums() const {
    std::vector<int> all = m_positive_numbers();
    std::vector<int> abundants = m_abundant_numbers();
	
    for (std::size_t i = 0; i < abundants.size(); ++i) {
        for (std::size_t j = i; j < abundants.size(); ++j) {
            const int index = abundants[i] + abundants[j];
            if (index < MAX)
                all[index - 1] = 0;
        }
    }

    int sum = 0;
    for (std::size_t i = 0; i < all.size(); ++i)
        sum += all[i];

    printf("Sum of all positive integers which cannot be written as sum of two abundant numbers == [%d]\n", sum);    
}

std::vector<int> pp::Problem_23::m_abundant_numbers() const {
    std::vector<int> abundant_numbers;
    for (int i = 1; i < MAX; ++i)
        if (i < m_sum_of_divisors(i))
            abundant_numbers.push_back(i);
    return abundant_numbers;
}

std::vector<int> pp::Problem_23::m_positive_numbers() const {
    std::vector<int> all_numbers;
    for (int i = 1; i < MAX; ++i)
        all_numbers.push_back(i);
    return all_numbers;
}

int pp::Problem_23::m_sum_of_divisors(int n) const {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i)
        if (n % i == 0)
            sum += i;
    return sum;    
}

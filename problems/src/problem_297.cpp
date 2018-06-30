#include "problem_297.h"
#include <cstdio>

//const std::size_t limit = 100000000000000000;
const std::size_t limit = 1000000;

project_euler::problems::Problem_297::Problem_297() {
    // Initialize the fibonacci numbers list
    m_fibonacci();
}

project_euler::problems::Problem_297::~Problem_297() {}

void project_euler::problems::Problem_297::zeckendorf() {
    std::size_t total = 0;

    for (std::size_t n = 1; n < limit; ++n) {
        //const int t = m_zeckendorf(n);
        total += m_zeckendorf(n);
    }

    printf("-----------------------------------------------------------\n");
    printf("                   0 < Z(n) < 10 ^ 17\n");
    printf("Z(n) == [%lu] \n", total);
    printf("-----------------------------------------------------------\n");
}

void project_euler::problems::Problem_297::m_fibonacci() {
    std::size_t A = 1;
    std::size_t B = 2;
    std::size_t C = 3;

    m_fibonacci_numbers.push_back(A);
    m_fibonacci_numbers.push_back(B);
    m_fibonacci_numbers.push_back(C);

    while (1) {
        A = B;
        B = C;
        C += A;
        if (C >= limit)
            break;
        m_fibonacci_numbers.push_back(C);
    }
}

std::size_t project_euler::problems::Problem_297::m_find(std::size_t n) {
    std::size_t i = m_fibonacci_numbers.size() - 1;

    while (m_fibonacci_numbers[i--] > n);
    return m_fibonacci_numbers[++i];
}

std::size_t project_euler::problems::Problem_297::m_zeckendorf(std::size_t n) {
    std::size_t counter = 0;

    while (n) {
        n -= m_find(n);
        ++counter;
    }

    return counter;
}

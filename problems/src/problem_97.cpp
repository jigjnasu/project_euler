/*
  This is the solution for Problem 97, (Large non-Mersenne prime) from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 4th, 2016
 */

#include "problem_97.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_97::Problem_97() {}

pp::Problem_97::~Problem_97() {}

// Let's try to calculate the 28433 × 2 ^ 7830457 + 1
void pp::Problem_97::large_prime() {
    std::string x;
    // Initialize it with 1
    x.push_back('0' + 1);

    // first caluclate power(2, 7830457)
    for (int i = 0; i < 7830457; ++i)
        m_multiply(x, 2);

    // Multiply the answer with 28433
    m_multiply(x, 28433);

    // Increment the final result by 1
    x[0]++;

    // Print the final solution
    m_print(x);
}

void pp::Problem_97::m_multiply(std::string& x, int y) {
    std::size_t iter = 0;
    int carry = 0;

    while (iter < x.size()) {
        const int value = carry + ((x[iter] - '0') * y);
        x[iter] = (value % 10) + '0';
        carry = value / 10;

        ++iter;

        // Restrict the multiplication with 10 digits only.
        // There is no need to caluclate all the digits as we need to show
        // Only last 10 digits as the answer
        if (iter >= 10)
            return;
    }

    while (carry) {
        x.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void pp::Problem_97::m_print(const std::string& x) {
    printf("Last 10 digits of the Large Non Mersenne Prime Number == [");
    for (int i = x.size() - 1; i >= 0; --i)
        printf("%d", x[i] - '0');
    printf("]\n");
}



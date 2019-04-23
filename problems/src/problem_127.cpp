/*
  This is solution for problem 127 (abc-hits) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : 24/04/2019
*/

#include "problem_127.h"
#include <cstdio>

project_euler::problems::Problem_127::Problem_127() {}

project_euler::problems::Problem_127::~Problem_127() {}

void project_euler::problems::Problem_127::sum(int n) {
    m_primes = m_get_primes(n);

    double sum = 0;
    for (int a = 1; a < 1000; ++a) {
        for (int b = a + 1; b < 1000; ++b) {
            const int c = a + b;
            if (c >= n) break;
            if (m_gcd(a, b) == 1 &&
                m_gcd(a, c) == 1 &&
                m_gcd(b, c) == 1) {
                const int f = m_factors_product(a * b * c);
                if (f < c) {
                    printf("%5d %5d %5d\n", a, b, c);
                    sum += c;
                }
            }
        }
    }
    printf("Summation of c < %d == [%.0f]\n", n, sum);
}

int project_euler::problems::Problem_127::m_gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return m_gcd(b, a % b);
}

std::vector<int> project_euler::problems::Problem_127::m_get_primes(int n) {
    std::vector<bool> d(n, true);
    for (int i = 2; i < n; ++i) {
        if (d[i]) {
            for (int j = i << 1; j < n; j = j + i)
                d[j] = false;
        }
    }

    std::vector<int> primes;
    for (std::size_t i = 2; i < d.size(); ++i)
        if (d[i])
            primes.push_back(i);
    return primes;
}

int project_euler::problems::Problem_127::m_factors_product(int n) {
    int p = 1;
    for (std::size_t i = 0; i < m_primes.size() && m_primes[i] <= n; ++i) {
        if (n % m_primes[i] == 0)
            p *= m_primes[i];
    }

    return p;
}

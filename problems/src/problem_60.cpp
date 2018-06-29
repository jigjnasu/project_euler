#include "Problem_60.h"
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>

project_euler::problems::Problem_60::Problem_60() {}

project_euler::problems::Problem_60::~Problem_60() {}

void project_euler::problems::Problem_60::prime_pair_sets() {
    m_seive();

    for (std::size_t a = 0; a < m_primes.size(); ++a) {
        for (std::size_t b = a + 1; b < m_primes.size(); ++b) {
            if (!m_pair(m_primes[a], m_primes[b])) continue;
            for (std::size_t c = b + 1; c < m_primes.size(); ++c) {
                if (!m_pair(m_primes[a], m_primes[c])) continue;
                if (!m_pair(m_primes[b], m_primes[c])) continue;
                for (std::size_t d = c + 1; d < m_primes.size(); ++d) {
                    if (!m_pair(m_primes[a], m_primes[d])) continue;
                    if (!m_pair(m_primes[b], m_primes[d])) continue;
                    if (!m_pair(m_primes[c], m_primes[d])) continue;
                    for (std::size_t e = d + 1; e < m_primes.size(); ++e) {
                        if (!m_pair(m_primes[a], m_primes[e])) continue;
                        if (!m_pair(m_primes[b], m_primes[e])) continue;
                        if (!m_pair(m_primes[c], m_primes[e])) continue;
                        if (!m_pair(m_primes[d], m_primes[e])) continue;
                        printf("[%d] [%d] [%d] [%d] [%d] == [%d]\n",
                               m_primes[a], m_primes[b], m_primes[c], m_primes[d], m_primes[e],
                               m_primes[a] + m_primes[b] + m_primes[c] + m_primes[d] + m_primes[e]);
                        return;
                    }
                }
            }
        }
    }
}

void project_euler::problems::Problem_60::m_seive() {
    std::vector<int> primes;
    for (int i = 0; i <= 10000; ++i)
        primes.push_back(i);

    for (std::size_t i = 2; i < primes.size(); ++i)
        if (static_cast<int>(i) == primes[i])
            for (std::size_t j = i * 2; j < primes.size(); j += i)
                primes[j] = 0;

    for (std::size_t i = 2; i < primes.size(); ++i)
        if (primes[i])
            m_primes.push_back(primes[i]);
}

void project_euler::problems::Problem_60::m_print() const {
    for (std::size_t i = 0; i < m_primes.size(); ++i)
        printf("%d ", m_primes[i]);
    printf("\n");
}

int project_euler::problems::Problem_60::m_pair(int a, int b) const {
    if (!m_is_prime(std::atoi(std::string(std::to_string(a) + std::to_string(b)).c_str())))
        return false;

    if (!m_is_prime(std::atoi(std::string(std::to_string(b) + std::to_string(a)).c_str())))
        return false;

    return true;
}

bool project_euler::problems::Problem_60::m_is_prime(int n) const {
    for (int i = 2; i <= std::sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

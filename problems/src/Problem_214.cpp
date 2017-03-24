#include "Problem_214.h"
#include "Maths.h"
#include <cstdio>

const std::size_t limit = 40000000;

project_euler::problems::Problem_214::Problem_214() {
    utility::maths::Maths<std::size_t> maths;
    m_phi_dictionary = maths.phi_all(limit - 1);
    for (std::size_t i = 0; i < limit; ++i) {
        m_chain_dictionary.push_back(0);
    }
}

project_euler::problems::Problem_214::~Problem_214() {}

void project_euler::problems::Problem_214::totient_chains() {
    std::size_t length = 25;
    std::size_t sum = 0;
    utility::maths::Maths<std::size_t> maths;

    for (std::size_t i = 2; i < limit; ++i) {
        if (m_chain_dictionary[i] == 0)
            m_chain_dictionary[i] = m_chain(i);
        
        if (m_chain_dictionary[i] == length && maths.is_prime(i))
            sum += i;
    }

    printf("------------------------------------------------------------------------\n");
    printf("Sum of all primes < [%lu] == [%lu]\n", limit, sum);
    printf("------------------------------------------------------------------------\n");
}

std::size_t project_euler::problems::Problem_214::m_chain(std::size_t n) {
    utility::maths::Maths<std::size_t> maths;
    int chain = 1;
    
    while (n != 1) {
        if (m_chain_dictionary[n])
            return chain - 1 + m_chain_dictionary[n];
        n = m_phi_dictionary[n];
        ++chain;
    }

    return chain;
}

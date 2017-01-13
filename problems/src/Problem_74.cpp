/*
  ProjectEuler.net
  Solution for Problem number 74 (Digit Factorial Chains)
  Rakesh Kumar, cpp.rakesh(at)gmail.com
  Jan 12th, 2017
 */

#include "Problem_74.h"
#include "Maths.h"
#include <cstdio>

#include <cstdio>
#include <vector>
#include <map>

const int limit = 1000000;

namespace pp = project_euler::problems;

pp::Problem_74::Problem_74() {
    utility::maths::Maths<int> maths;
    for (int i = 0; i < 10; ++i)
        m_factorials.push_back(maths.factorial(i));
}

pp::Problem_74::~Problem_74() {}

void pp::Problem_74::digit_factorial_chains() {
    int count = 0;
    for (int i = 1; i < limit; ++i) {
        const int chain = m_factorial_chain(i);
        m_chain_dictionary[i] = chain; 
        if (chain == 60)
            ++count;
    }

    printf("Total number of Digit Foctorial chain 60 numbers long < [%d] == [%d]\n", limit, count);
}

// Calculate the chain and store into a dictionary.
// We are calculating it only when we have not in the dictionary.
// Dynamic Programming.
int pp::Problem_74::m_factorial_chain(int number) {
    if (m_chain_dictionary[number])
        return m_chain_dictionary[number];

    int count = 1;
    std::map<int, int> chain;
    chain[number] = count;
    int next = m_sum(number);
    
    while (!chain[next]) {
        if (m_chain_dictionary[next])
            return m_chain_dictionary[next] + chain.size() - 1;
        chain[next] = ++count;
        next = m_sum(next);
    }

    m_chain_dictionary[next] = chain.size() - chain[next] + 1;
    
    return chain.size();
}

int pp::Problem_74::m_sum(int number) {
    int sum = 0;
    while (number) {
        sum += m_factorials[number % 10];
        number /= 10;
    }

    return sum;
}

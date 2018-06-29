/*
  projecteuler.net
  Solution for problem number 60 (Prime Pair Sets)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 02/08/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_60_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_60_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_60 {
        public:
            Problem_60();
            ~Problem_60();

            void prime_pair_sets();

        private:
            std::vector<int> m_primes;

            void m_seive();
            void m_print() const;
            int m_pair(int a, int b) const;
            bool m_is_prime(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_60_H_

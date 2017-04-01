/*
  projecteuler.net
  Solution for problem number 248 (Numbers for which Euler’s totient function equals 13!)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 01/04/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_248_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_248_H_

#include <cstdio>

namespace project_euler {
    namespace problems {
        class Problem_248 {
        public:
            Problem_248();
            ~Problem_248();

            void totient() const;

        private:
            std::size_t m_gcd(std::size_t a, std::size_t b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_248_H_

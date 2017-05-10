/*
  projecteuler.net
  Solution for problem number 53 (Combinatoric Selections)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 10/05/2017
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_53_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_53_H_

#include "Integer.h"

namespace project_euler {
    namespace problems {
        class Problem_53 {
        public:
            Problem_53();
            ~Problem_53();

            void combinatronic_selection() const;

        private:
            utility::integer::Integer m_binomial(int n, int r) const;
            int m_min(int a, int b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_53_H_

/*
  projecteuler.net
  Solution for problem number 297 (Zeckendorf Representation)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 01/04/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_297_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_297_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_297 {
        public:
            Problem_297();
            ~Problem_297();

            void zeckendorf();

        private:
            std::vector<std::size_t> m_fibonacci_numbers;
            
            void m_fibonacci();
            std::size_t m_find(std::size_t n);
            std::size_t m_zeckendorf(std::size_t n);
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_297_H_

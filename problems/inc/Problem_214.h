/*
  projecteuler.net
  Solution for problem number 214 (Totient Chains)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 25/03/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_214_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_214_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_214 {
        public:
            Problem_214();
            ~Problem_214();

            void totient_chains();
        private:
            std::size_t m_chain(std::size_t n);

            std::vector<std::size_t> m_phi_dictionary;
            std::vector<std::size_t> m_chain_dictionary;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_214_H_

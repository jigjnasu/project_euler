/*
  projecteuler.net
  Solution for problem number 31 (Coin Sums)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 06/04/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_31_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_31_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_31 {
        public:
            Problem_31();
            ~Problem_31();
            
            void coin_sums() const;
            
        private:
            int m_coin_sums_iterative(int amount) const;
            int m_coin_sums_recursive(int amount, int pos) const;
            int m_coin_sums_dp(int amount, int pos,
                               std::vector< std::vector<int> >& memo) const;
            int m_coin_sums_dp_bottom_up(int amount) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_31_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_50_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_50_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_50 {
        public:
            Problem_50();
            ~Problem_50();

            void consecutive_prime_sum() const;

        private:
            std::vector<int> m_prime_sums() const;
            void m_largest_sum(const std::vector<int>& prime_sums) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_50_H_

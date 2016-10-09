#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_23_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_23_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_23 {
        public:
            Problem_23();
            ~Problem_23();

            void non_abundant_sums() const;

        private:
            std::vector<int> m_abundant_numbers() const;
            std::vector<int> m_positive_numbers() const;

            int m_sum_of_divisors(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_23_H_

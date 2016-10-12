#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_47_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_47_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_47 {
        public:
            Problem_47();
            ~Problem_47();

            void distinct_prime_factors() const;

        private:
            std::vector<int> m_factors(int n, const std::vector<int>& prime_numbers) const;
            bool m_is_distinct_factor(const std::vector<int>& factors) const;
            void m_print(int n, const std::vector<int>& factors) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_47_H_

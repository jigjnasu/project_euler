#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_127_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_127_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_127 {
        public:
            Problem_127();
            ~Problem_127();

            void sum(int n);

        private:
            std::vector<int> m_primes;

            int m_gcd(int a, int b);
            std::vector<int> m_get_primes(int n);
            int m_factors_product(int n);
        };
    };
};

#endif // PROJECT_EULER_PROBLEM_PROBLEMS_127_H_

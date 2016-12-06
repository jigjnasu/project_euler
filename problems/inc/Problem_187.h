#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_187_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_187_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_187 {
        public:
            Problem_187();
            ~Problem_187();
            
            int semi_primes(std::size_t n) const;

        private:
            int m_square_factors(std::size_t n, const std::vector<std::size_t>& prime_numbers) const;
            int m_2_factors(std::size_t n, const std::vector<std::size_t>& prime_numbers) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_187_H_

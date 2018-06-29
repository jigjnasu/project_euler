#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_35_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_35_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_35 {
        public:
            Problem_35();
            ~Problem_35();

            void circular_primes() const;

        private:
            void m_rotate_left(std::string& number) const;
            bool m_is_circular_prime(std::string number) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_35_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_37_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_37_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_37 {
        public:
            Problem_37();
            ~Problem_37();

            void truncatable_primes() const;

        private:
            bool m_is_trunctable_prime(const std::string& number) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_37_H_

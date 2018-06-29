#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_27_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_27_H_

namespace project_euler {
    namespace problems {
        class Problem_27 {
        public:
            Problem_27();
            ~Problem_27();

            void quadratic_primes() const;

        private:
            int m_quadratic_prime(int a, int b, int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_27_H_

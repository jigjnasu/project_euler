#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_24_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_24_H_

#include <cstdio>

namespace project_euler {
    namespace problems {
        class Problem_24 {
        public:
            Problem_24();
            ~Problem_24();

            void permutation_generator() const;

        private:
            template <std::size_t size>
            void m_get_next(int (&A)[size]) const;

            template <std::size_t size>
            void m_print(const int(&V)[size]) const;

            void m_swap(int& A, int &B) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_24_H_

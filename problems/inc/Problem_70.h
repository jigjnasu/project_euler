#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_70_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_70_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_70 {
        public:
            Problem_70();
            ~Problem_70();

            void totient_permutation() const;

        private:
            bool m_is_permutation(std::size_t a, std::size_t b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_70_H_

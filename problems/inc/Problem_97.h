#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_97_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_97_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_97 {
        public:
            Problem_97();
            ~Problem_97();

            void large_prime();

        private:
            void m_multiply(std::string& x, int y);
            void m_print(const std::string& x);
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_97_H_

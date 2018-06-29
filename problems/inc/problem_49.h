#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_49_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_49_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_49 {
        public:
            Problem_49();
            ~Problem_49();

            void prime_permutations() const;

        private:
            bool m_is_permutation(std::string a, std::string b, std::string c) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_49_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_34_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_34_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_34 {
        public:
            Problem_34();
            ~Problem_34();

            void digit_factorials() const;

        private:
            bool m_is_equal(int n, const std::vector<int>& factorials) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_34_H_

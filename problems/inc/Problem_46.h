#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_46_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_46_H_

#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_46 {
        public:
            Problem_46();
            ~Problem_46();

            void goldbach_conjecture() const;

        private:
            bool m_is_goldbach_conjecture(int n, const std::vector<int>& prime_numbers) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_46_H_

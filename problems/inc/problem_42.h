#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_42_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_42_H_

#include <string>
#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_42 {
        public:
            Problem_42();
            ~Problem_42();

            void count_coded_triangle_numbers(const std::string& file) const;

        private:
            std::vector<int> m_coded_triangle_numbers() const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_42_H_

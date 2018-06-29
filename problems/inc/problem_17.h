#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_17_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_17_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_17 {
        public:
            Problem_17();
            ~Problem_17();

            void letter_count() const;

        private:
            std::string m_count(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_17_H_

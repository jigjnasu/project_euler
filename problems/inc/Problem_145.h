#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_145_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_145_H_

namespace project_euler {
    namespace problems {
        class Problem_145 {
        public:
            Problem_145();
            ~Problem_145();

            void count_reversables() const;

        private:
            bool m_is_reversable(int n) const;
            void m_swap(char& a, char& b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_145_H_

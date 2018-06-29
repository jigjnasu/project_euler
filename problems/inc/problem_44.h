#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_44_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_44_H_

namespace project_euler {
    namespace problems {
        class Problem_44 {
        public:
            Problem_44();
            ~Problem_44();

            void min_difference() const;

        public:
            int m_pentagon_number(int n) const;
            bool m_is_pentagon_number(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_44_H_

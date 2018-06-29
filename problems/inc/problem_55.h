#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_55_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_55_H_

namespace project_euler {
    namespace problems {
        class Problem_55 {
        public:
            Problem_55();
            ~Problem_55();

            void lychrel_numbers(int max) const;

            bool m_is_lychrel_number(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_55_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_19_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_19_H_

namespace project_euler {
    namespace problems {
        class Problem_19 {
        public:
            Problem_19();
            ~Problem_19();

            void sundays() const;

        private:
            bool m_is_leap_year(int YYYY) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_19_H_

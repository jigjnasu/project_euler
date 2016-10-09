#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_30_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_30_H_

namespace project_euler {
    namespace problems {
        class Problem_30 {
        public:
            Problem_30();
            ~Problem_30();

            void digit_fifth_power() const;

        private:
            bool m_is_digit_fifth_power(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_30_H_

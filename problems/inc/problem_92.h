#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_92_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_92_H_

namespace project_euler {
    namespace problems {
        class Problem_92 {
        public:
            Problem_92();
            ~Problem_92();

            void square_digit_chains() const;

        private:
            int m_get_square_digit(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_92_H_

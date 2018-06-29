#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_33_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_33_H_

namespace project_euler {
    namespace problems {
        class Problem_33 {
        public:
            Problem_33();
            ~Problem_33();

            void digit_cancelling_fractions() const;

        private:
            bool m_is_cancelling_fractions(int n, int d) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_33_H_

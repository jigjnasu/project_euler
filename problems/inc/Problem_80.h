#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_80_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_80_H_

namespace project_euler {
    namespace problems {
        class Problem_80 {
        public:
            Problem_80();
            ~Problem_80();

            void square_root_digital_expansion() const;

        private:
            int m_square_root_sum(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_80_H_

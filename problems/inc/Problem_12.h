#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_12_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_12_H_

typedef unsigned long long int u_long;

namespace project_euler {
    namespace problems {
        class Problem_12 {
        public:
            Problem_12();
            ~Problem_12();

            void max_divisible_triangular_number() const;

        private:
            int m_count_divisor(const u_long& n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_12_H_

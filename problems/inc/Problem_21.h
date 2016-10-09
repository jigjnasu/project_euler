#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_21_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_21_H_

namespace project_euler {
    namespace problems {
        class Problem_21 {
        public:
            Problem_21();
            ~Problem_21();

            void sum_of_amicable_numbers() const;
            
        private:
            int m_divisors_sum(int n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_21_H_

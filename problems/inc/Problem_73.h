#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_73_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_73_H_

namespace project_euler {
    namespace problems {
        class Problem_73 {
        public:
            Problem_73();
            ~Problem_73();

            void counting_fractions();

        private:
            int m_counter;
            
            void m_counting_fractions(int a, int b, int c, int d, int n);
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_73_H_

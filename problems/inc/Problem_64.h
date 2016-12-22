#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_64_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_64_H_

namespace project_euler {
    namespace problems {
        class Problem_64 {
        public:
            Problem_64();
            ~Problem_64();

            void count_continued_fractions_periods(int n) const;

        private:
            int m_length_of_contined_fractions(int s) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_64_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_14_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_14_H_

typedef unsigned long long int u_l;

namespace project_euler {
    namespace problems {
        class Problem_14 {
        public:
            Problem_14();
            ~Problem_14();

            void collatz_sequence() const;

        private:
            int m_sequence_chain(u_l n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_14_H_

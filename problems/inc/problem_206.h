#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_206_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_206_H_

using ull = unsigned long long int;

namespace project_euler {
    namespace problems {
        class Problem_206 {
        public:
            Problem_206();
            ~Problem_206();

            void concealed_square() const;

        private:
            bool check(ull n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEM_PROBLEMS_206_H_

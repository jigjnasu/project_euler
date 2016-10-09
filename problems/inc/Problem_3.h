#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_3_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_3_H_

typedef unsigned long long int u_long;

namespace project_euler {
    namespace problems {
        class Problem_3 {
        public:
            Problem_3();
            ~Problem_3();

            void largest_factor(const u_long& n) const;
        };  
    };  
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_3_H

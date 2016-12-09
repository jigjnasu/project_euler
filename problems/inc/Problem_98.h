#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_98_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_98_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_98 {
        public:
            Problem_98();
            ~Problem_98();

            int anagramic_squares(const std::string& file) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_98_H_

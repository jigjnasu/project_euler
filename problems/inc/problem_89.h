#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_89_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_89_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_89 {
        public:
            Problem_89();
            ~Problem_89();

            void roman_numbers() const;

        private:
            std::string roman(int n) const;
            int random(int min, int max) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_89_H_

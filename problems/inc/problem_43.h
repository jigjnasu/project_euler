#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_43_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_43_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_43 {
        public:
            Problem_43();
            ~Problem_43();

            void sub_string_divisiblity() const;
            
        private:
            bool m_is_sub_string_divisible(const std::string& number) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_43_H_

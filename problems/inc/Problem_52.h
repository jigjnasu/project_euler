#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_52_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_52_H_

#include <string>

namespace project_euler {
    namespace problems {
        class Problem_52 {
        public:
            Problem_52();
            ~Problem_52();

            void permutated_multiples() const;

        private:
            bool m_all_permutated(std::string x1, std::string x2,
                                  std::string x3, std::string x4,
                                  std::string x5, std::string x6) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_52_H_

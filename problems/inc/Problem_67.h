/*
  projecteuler.net
  Solution for problem number 67 (Maximum path sum II)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 02/08/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_67_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_67_H_

#include <vector>
#include <string>

namespace project_euler {
    namespace problems {
        class Problem_67 {
        public:
            Problem_67();
            ~Problem_67();

            void max_path() const;

        private:
            std::vector<std::vector<int>> m_get_pyramid(const std::string& file) const;
            int m_max(int a, int b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_67_H_

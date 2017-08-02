/*
  projecteuler.net
  Solution for problem number 18 (Maximum path sum I)
  Author: Rakesh Kumar, cpp.rakesh(at)gmail.com
  Date: 02/08/2107
 */

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_18_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_18_H_

namespace project_euler {
    namespace problems {
        class Problem_18 {
        public:
            Problem_18();
            ~Problem_18();

            void max_path() const;

        private:
            int m_max(int a, int b) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_18_H_

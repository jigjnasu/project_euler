#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_74_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_74_H_

#include <map>
#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_74 {
        public:
            Problem_74();
            ~Problem_74();

            void digit_factorial_chains();

        private:
            std::vector<int>   m_factorials;
            std::map<int, int> m_chain_dictionary;
            
            int m_factorial_chain(int number);
            int m_sum(int number);
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_74_H_

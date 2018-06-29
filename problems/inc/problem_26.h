#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_26_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_26_H_

#include <string>
#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_26 {
        public:
            Problem_26();
            ~Problem_26();

            void reciprocal_cycles() const;

        private:
            std::string m_fraction(int x, int y) const;
            bool m_is_in_dictionary(const std::vector<int>& dictionary,
                                    int key, int pos) const;
            int m_get_max_recurence_count(const std::string& number) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_26_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_54_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_54_H_

#include "Card.h"
#include <string>
#include <vector>

namespace project_euler {
    namespace problems {
        class Problem_54 {
        public:
            Problem_54();
            ~Problem_54();

            void count_player_wins(int player) const;

        private:
            bool m_read_data(const std::string& file,
                             std::vector< std::vector<Card> >& A,
                             std::vector< std::vector<Card> >& B) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_54_H_

#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_45_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_45_H_

namespace project_euler {
    namespace problems {
        class Problem_45 {
        public:
            Problem_45();
            ~Problem_45();

            void next_number() const;

        private:
            bool m_is_pentagonal(const double& n) const;
            double m_hexagonal(const double& n) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_45_H_

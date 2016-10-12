#ifndef PROJECT_EULER_PROBLEMS_PROBLEM_32_H_
#define PROJECT_EULER_PROBLEMS_PROBLEM_32_H_

namespace project_euler {
    namespace problems {
        class Problem_32 {
        public:
            Problem_32();
            ~Problem_32();

            void pandigital_product() const;

        private:
            bool m_is_pandigital(int a, int b, int c) const;
        };
    };
};

#endif // PROJECT_EULER_PROBLEMS_PROBLEM_32_H_

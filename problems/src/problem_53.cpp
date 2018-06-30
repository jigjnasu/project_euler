#include "problem_53.h"
#include <cstdio>
#include <vector>

const int SIZE = 1e+6;

project_euler::problems::Problem_53::Problem_53() {}

project_euler::problems::Problem_53::~Problem_53() {}

void project_euler::problems::Problem_53::combinatronic_selection() const {
    int count = 0;
    for (int n = 1; n <= 100; ++n) {
        for (int r = 1; r < n; ++r) {
            if (m_binomial(n, r) > SIZE)
                ++count;
        }
    }

    printf("-------------------------------------------------\n");
    printf("Binomial Coffecients more than [%d] == [%d]\n", SIZE, count);
    printf("-------------------------------------------------\n");
}

utility::integer::Integer project_euler::problems::Problem_53::m_binomial(int n, int r) const {
    std::vector<utility::integer::Integer> C;
    for (int i = 0; i <= r; ++i)
        C.push_back(0);

    C[0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = m_min(i, r); j > 0; --j)
            C[j] += C[j - 1];

    return C[r];
}

int project_euler::problems::Problem_53::m_min(int a, int b) const {
    return a < b ? a : b;
}

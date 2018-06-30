#include "problem_145.h"
#include <cstdio>
#include <string>

const int limit = 1e+9;

project_euler::problems::Problem_145::Problem_145() {}

project_euler::problems::Problem_145::~Problem_145() {}

void project_euler::problems::Problem_145::count_reversables() const {
    int count = 0;
    for (int n = 1; n < limit; ++n)
        if (m_is_reversable(n))
            ++count;

    printf("--------------------------------------------------------\n");
    printf("Reversable numbers under [%d] == [%d]\n", limit, count);
    printf("--------------------------------------------------------\n");
}

bool project_euler::problems::Problem_145::m_is_reversable(int n) const {
    if (n % 10 == 0)
        return false;

    int t = n;
    int r = 0;

    while (t) {
        r = (r * 10) + (t % 10);
        t /= 10;
    }

    int s = n + r;
    while (s) {
        if ((s % 10) % 2 == 0)
            return false;
        s /= 10;
    }

    return true;
}

void project_euler::problems::Problem_145::m_swap(char& a, char& b) const {
    a ^= b;
    b ^= a;
    a ^= b;
}

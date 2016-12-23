#include "Problem_65.h"
#include <cstdio>
#include <vector>

namespace pp = project_euler::problems;

pp::Problem_65::Problem_65() {}

pp::Problem_65::~Problem_65() {}

void pp::Problem_65::convergents_of_e() const {
    // numerator
    std::vector<int> p;
    // denominator
    std::vector<int> q;

    p.push_back(1);
    p.push_back(1);

    q.push_back(1);
    q.push_back(0);

    for (int a = 2; a <= 10; ++a) {
        p.push_back((a * p[a - 1]) + p[a - 2]);
        q.push_back((a * q[a - 1]) + q[a - 2]);
    }

    for (std::size_t i = 0; i < p.size(); ++i) {
        printf("%d / %d\n", p[i], q[i]);
    }
}

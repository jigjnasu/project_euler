#include "Problem_69.h"
#include <vector>
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_69::Problem_69() {}

pp::Problem_69::~Problem_69() {}

void pp::Problem_69::totient_maximum(int n) const {
    std::vector<double> phi;
    for (int i = 0; i <= n; ++i)
        phi.push_back(i);

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= n; j += i)
                phi[j] = (phi[j] * (i - 1)) / static_cast<double>(i);
        }
    }

    double max = 0.0f;
    int index = 0;
    for (int i = 2; i <= n; ++i) {
        const double value = i / phi[i];
        if (value > max) {
            max = value;
            index = i;
        }
    }
    
    printf("Maximum totient from 2 .......... 1000000\n");
    printf("N == [%d] || phi[n] == [%.0f] || n / phi(n) == [%.8f]\n", index, phi[index], max);
}

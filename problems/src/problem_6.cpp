#include "Problem_6.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_6::Problem_6() {}

pp::Problem_6::~Problem_6() {}

void pp::Problem_6::sum_of_squares(int n) const {
    const int S1 = (n * (n + 1)) / 2;
    const int S2 = (n * (n + 1) * ((2 * n) + 1)) / 6;

    printf("Sum of squares series till [%d] == [%d]\n", n, (S1 * S1) - S2);
    
}

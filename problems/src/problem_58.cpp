#include "problem_58.h"
#include "maths.h"
#include <cstdio>
#include <cmath>

project_euler::problems::Problem_58::Problem_58() {}

project_euler::problems::Problem_58::~Problem_58() {}

void project_euler::problems::Problem_58::spiral_primes() const {
    int i = 1;
    int diagnol = 1;
    int total = 1;
    int count = 0;
    utility::maths::Maths<int> maths;
    while (1) {
        for (int n = 0; n < 4; ++n) {
            diagnol += (i * 2);
            if (maths.is_prime(diagnol))
                ++count;
        }

        total += 4;
        if ((count / static_cast<double>(total)) < 0.1f) {
            printf("---------------------------------------------------------\n");
            printf("Spiral primes ration less than 10 percent is at length == [%.0f]\n", std::sqrt(diagnol));
            printf("---------------------------------------------------------\n");
            break;
        }
        ++i;
    }
}

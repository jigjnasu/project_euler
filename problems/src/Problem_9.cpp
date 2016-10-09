#include "Problem_9.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_9::Problem_9() {}

pp::Problem_9::~Problem_9() {}

void pp::Problem_9::special_triplet() const {
    for (int a = 1; a < 1000 / 2; ++a) {
        for (int b = 1; b < 1000 / 2; ++b) {
            const int c = 1000 - (a + b);
            if (((a * a) + (b * b)) == (c * c)) {
                printf("Product == [%d]\n", a * b * c);
                return;
            }
        }
    }    
}

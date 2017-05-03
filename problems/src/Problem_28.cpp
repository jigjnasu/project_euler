#include "Problem_28.h"
#include <cstdio>

project_euler::problems::Problem_28::Problem_28() {}

project_euler::problems::Problem_28::~Problem_28() {}

void project_euler::problems::Problem_28::diagnols_sum() const {
    const int n = 1001;
    int diagnol = 1;
    int sum = diagnol;

    int i = 1;
    while (1) {
        for (int j = 0; j < 4; ++j) {
            diagnol += (i * 2);
            if (diagnol > n * n) {
                printf("-----------------------------------------------\n");
                printf("Sum of diagnols of [%d] X [%d] spiral == [%d]\n", n, n, sum);
                printf("-----------------------------------------------\n");                
                return;
            }
            
            sum += diagnol;
        }
        ++i;
    }
}

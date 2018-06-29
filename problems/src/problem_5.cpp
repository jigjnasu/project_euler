#include "Problem_5.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_5::Problem_5() {}

pp::Problem_5::~Problem_5() {}

void pp::Problem_5::smallest_multiple(int max_divisibles) const {
    int number = max_divisibles + 1;
    while (1) {
        bool is_quit = true;
        for (int i = 2; i <= max_divisibles; ++i) {
            if (number % i) {
                is_quit = false;
                break;
            }
        }

        if (is_quit) {
            printf("Smallest number === [%d]\n", number);
            return;
        }
        
        ++number;
    }
}

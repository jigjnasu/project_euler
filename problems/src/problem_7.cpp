#include "Problem_7.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;
namespace um = utility::maths;

pp::Problem_7::Problem_7() {}

pp::Problem_7::~Problem_7() {}

void pp::Problem_7::prime_number(int n) const {
    um::Maths<int> math;
    int number = 2;
    int i = 0;
    while (i != n) {
        if (math.is_prime(number))
            ++i;
        ++number;
    }

    printf("[%d] prime number == [%d]\n", n, number - 1);
}

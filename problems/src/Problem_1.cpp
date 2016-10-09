#include "Problem_1.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_1::Problem_1() {}

pp::Problem_1::~Problem_1() {}

int pp::Problem_1::sum(int i, int n) const {
    int a = i;
    int l = (n % i == 0) ? n : n - (n % i);
    int k = l / a;

    return (k * (a + l)) >> 1;    
}

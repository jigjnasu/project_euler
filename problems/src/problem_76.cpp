/*
  This is solution for problem 76 (Counting Sums) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date : 24/04/2017
*/

#include "problem_76.h"
#include <cstdio>
#include <vector>

project_euler::problems::Problem_76::Problem_76() {}

project_euler::problems::Problem_76::~Problem_76() {}

void project_euler::problems::Problem_76::count_sum(int max) const {
    std::vector<int> sums;
    for (int i = 0; i <= max; ++i)
        sums.push_back(0);

    sums[0] = 1;
    for (int i = 1; i < max; ++i)
        for (int j = i; j <= max; ++j)
            sums[j] += sums[j - i];

    printf("Total number of ways in which [%d] can be written == [%d]\n", max, sums[max]);
}

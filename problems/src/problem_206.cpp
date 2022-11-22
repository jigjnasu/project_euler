/*
  This is the solution for Problem 206, Concealed Square from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 22nd, 2022
 */

#include "problem_206.h"
#include <cstdio>
#include <math.h>
#include <string>

namespace pp = project_euler::problems;

pp::Problem_206::Problem_206() {}

pp::Problem_206::~Problem_206() {}

void pp::Problem_206::concealed_square() const {
    ull start = std::sqrt(1020304050607080900);
    ull end = std::sqrt(1929394959697989990);
    for (ull i = start; i <= end; i += 10) {
        if (check(i)) {
            printf("[%llu] has form 1_2_3_4_5_6_7_8_9_0 == [%llu]\n", i, i * i);
            break;
        }
    }
}

bool pp::Problem_206::check(ull n) const {
    const std::string check_string = "1_2_3_4_5_6_7_8_9_0";
    ull x = n * n;
    std::string xs = std::to_string(x);
    for (std::size_t i = 0; i < check_string.size(); i += 2)
        if (check_string[i] != xs[i])
            return false;
    return true;
}
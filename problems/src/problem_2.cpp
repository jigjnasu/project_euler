/*
  ProjectEuler.net
  Problem 2 (Even Fibonacci numbers)
  Rakesh Kumar, cpp.rakesh(at)gmail.com
 */

#include "problem_2.h"

namespace pp = project_euler::problems;

pp::Problem_2::Problem_2() {}

pp::Problem_2::~Problem_2() {}

int pp::Problem_2::sum() const {
    int A = 1;
    int B = 2;
    int C = A + B;
    int S = 2;

    while (C < 4000000) {
        if (C % 2 == 0)
            S += C;
        A = B;
        B = C;
        C = A + B;
    }

    return S;
}

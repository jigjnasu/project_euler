/*
  This is the solution for Problem 57, (Square Root Convergents) from ProjectEuler.net
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 16th, 2016
 */

#include "Problem_57.h"
#include "Integer.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_57::Problem_57() {}

pp::Problem_57::~Problem_57() {}

void pp::Problem_57::square_root_convergents() const {
    utility::integer::Integer N(3);
    utility::integer::Integer D(2);

    int i = 0;
    int count = 0;
    while (i < 1000) {
        if (N.size() > D.size())
            ++count;            
        
        const utility::integer::Integer T = N;
        
        N += D * 2;
        D += T;

        ++i;
    }

    printf("------------------------------------------------------------------\n");
    printf("Square convergents till 1000 have [%d] numerator size more than denominator\n", count);
    printf("------------------------------------------------------------------\n");    
}

/*
  This is solution for problem 48 (Self Powers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
*/

#include "Problem_48.h"
#include "Integer.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_48::Problem_48() {}

pp::Problem_48::~Problem_48() {}

void pp::Problem_48::self_powers() const {
    utility::integer::Integer power_sum(0);
    utility::maths::Maths<utility::integer::Integer> math;

    for (int i = 1; i <= 1000; ++i) {
        utility::integer::Integer number = math.power(i, i);
	power_sum += number;
    }

    printf("Self power sum is here ----> \n");
    power_sum.Print();
}

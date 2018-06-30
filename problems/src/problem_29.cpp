/*
  This is solution for problem 29 (Distinct Powers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "problem_29.h"
#include "integer.h"
#include "maths.h"
#include <cstdio>
#include <set>
#include <cmath>

namespace pp = project_euler::problems;

pp::Problem_29::Problem_29() {}

pp::Problem_29::~Problem_29() {}

void pp::Problem_29::distinct_powers() const {
    utility::maths::Maths<utility::integer::Integer> maths;
    std::set<std::string> distinct_numbers;
    for (int a = 2; a <= 100; ++a)
	for (int b = 2; b <= 100; ++b)
	    distinct_numbers.insert(maths.power(a, b).get_reverse());

    printf("Distinct powers count == [%lu]\n", distinct_numbers.size());
}

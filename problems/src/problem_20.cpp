#include "Problem_20.h"
#include "Integer.h"
#include "Maths.h"
#include "String.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_20::Problem_20() {}

pp::Problem_20::~Problem_20() {}

void pp::Problem_20::sum_of_factorial_digits(int n) const {
    utility::maths::Maths<utility::integer::Integer> maths;
    utility::string::String<int> str;
    printf("Sum of digits of 100! == [%d]\n", str.sum_of_digits(maths.factorial(n).get_reverse()));
}

#include "Problem_16.h"
#include "Integer.h"
#include "Maths.h"
#include "String.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_16::Problem_16() {}

pp::Problem_16::~Problem_16() {}

void pp::Problem_16::sum() const {
    const int y = 1000;
    utility::integer::Integer x(2);

    utility::maths::Maths<utility::integer::Integer> maths;

    utility::string::String<int> str;

    printf("Sum of 2 ^ 1000 digits == [%d]\n", str.sum_of_digits(maths.power(x, y).get_reverse()));
}

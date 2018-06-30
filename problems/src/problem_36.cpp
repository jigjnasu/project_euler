#include "problem_36.h"
#include "common.h"
#include <cstdio>
#include <string>

namespace pp = project_euler::problems;

const int MILLION = 1000000;

pp::Problem_36::Problem_36() {}

pp::Problem_36::~Problem_36() {}

void pp::Problem_36::double_base_palindromes() const {
    utility::common::Common<int> common;
    int sum = 0;

    for (int i = 1; i < MILLION; ++i)
        if (common.is_palindrome(common.to_binary(i)) &&
            common.is_palindrome(common.to_string(i)))
            sum += i;
    printf("Sum of all binary and decimal numbers under million == [%d]\n", sum);
}

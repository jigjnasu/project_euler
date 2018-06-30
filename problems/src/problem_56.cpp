/*
  This is solution for problem 56 (Powerful digit sum) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 25th, 2016
*/

#include "problem_56.h"
#include "integer.h"
#include "maths.h"
#include "string.h"
#include <string>
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_56::Problem_56() {}

pp::Problem_56::~Problem_56() {}

void pp::Problem_56::powerful_digit_sum() const {
    int max_sum = 0;
    int i = 0;
    int j = 0;
    utility::string::String<int> string;
    utility::maths::Maths<utility::integer::Integer> math;

    for (int a = 2; a < 100; ++a) {
        for (int b = 2; b < 100; ++b) {
            const int sum = string.sum_of_digits(math.power(a, b).get_reverse());
            if (sum > max_sum) {
                i = a;
                j = b;
                max_sum = sum;
            }
        }
    }

    printf("-----------------------------------------------------------------\n");
    printf("Powerful Digit Max Sum [%d] ^ [%d] == [%d]\n", i, j, max_sum);
    printf("-----------------------------------------------------------------\n");
}

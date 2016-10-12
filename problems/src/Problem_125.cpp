/*
  This is solution for problem 125 (Palindromic sums) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 3rd, 2016
*/

#include "Problem_125.h"
#include "Common.h"
#include <cstdio>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

typedef unsigned long long int u_long;
const u_long max = 100000000;

namespace pp = project_euler::problems;

pp::Problem_125::Problem_125() {}

pp::Problem_125::~Problem_125() {}

void pp::Problem_125::palindromic_sums() const {
    utility::common::Common<u_long> common;
    const int limit = std::sqrt(max);
    std::set<u_long> numbers;
    u_long sum_of_numbers = 0;

    for (int i = 1; i <= limit; ++i) {
        u_long number = i * i;
        for (int j = i + 1; j <= limit; ++j) {
            number += j * j;

            if (number > max)
                break;

            if (common.is_palindrome(common.to_string(number)))
                numbers.insert(number);
        }
    }

    for (std::set<u_long>::const_iterator it = numbers.begin();
         it != numbers.end(); ++it)
        sum_of_numbers += *it;
	
    printf("--------------------------------------------------------\n");
    printf("Sum of all numbers below 10 ^ 8 == [%llu]\n", sum_of_numbers);
    printf("--------------------------------------------------------\n");    
}

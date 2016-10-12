/*
  This is solution for problem 40 (Champernowne's constant) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 14th, 2016
*/

#include "Problem_40.h"
#include "Common.h"
#include <cstdio>
#include <string>

namespace pp = project_euler::problems;

pp::Problem_40::Problem_40() {}

pp::Problem_40::~Problem_40() {}

void pp::Problem_40::champernowne_constant() const {
    utility::common::Common<int> common;
    std::string number;
    int i = 1;
    while (number.size() < 1000000)
        number += common.to_string(i++);

    printf("-----------------------------------------------------\n");
    printf("%c %c %c %c %c %c %c\n", number[0], number[9], number[99], number[999], number[9999], number[99999], number[999999]);
    printf("Champernowne Constant == [%d]\n", (number[0] - '0') *
           (number[9] - '0') * (number[99] - '0') * (number[999] - '0') *
           (number[9999] - '0') * (number[99999] - '0') * (number[999999] - '0'));
    printf("-----------------------------------------------------\n");
}

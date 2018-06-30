#include "problem_38.h"
#include "common.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_38::Problem_38() {}

pp::Problem_38::~Problem_38() {}

void pp::Problem_38::pandigital_multiples() const {
    utility::common::Common<int> common;
    std::string largest_number;
    for (int i = 1; i <= 10000; ++i) {
        std::string number;
        int j = 1;
        while (1) {
            number += common.to_string(i * j);
            if (number.size() >= 9) {
                if (common.is_pandigital(number, false)) {
                    if (number > largest_number)
                        largest_number = number;
                }
                break;
            }
            ++j;
        }
    }

    printf("Largest pandigtial multiple number == [%s]\n", largest_number.c_str());
}

/*
  This is solution for problem 99 (Largest exponential) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : Sep 14th, 2016
*/

#include "Problem_99.h"
#include "Common.h"
#include <cmath>
#include <cstdio>
#include <fstream>

namespace pp = project_euler::problems;

pp::Problem_99::Problem_99() {}

pp::Problem_99::~Problem_99() {}

void pp::Problem_99::largest_number(const std::string& file) const {
    utility::common::Common<int> common;
    std::ifstream ifs(file.c_str());
    int line_number = 1;
    double max_number = 0;
    int max_line_number = 0;
    
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            const std::size_t pos = line.find(",");
            const int base = common.to_number(line.substr(0, pos + 1).c_str());
            const int exp = common.to_number(line.substr(pos + 1, line.size() - pos).c_str());
            const double number = exp * std::log(base);
            if (number > max_number) {
                max_line_number = line_number;
                max_number = number;
            }

            ++line_number;
        }

        ifs.close();
    } else {
        printf("Error in opening [%s] file\n", file.c_str());
    }

    printf("-----------------------------------------------------\n");
    printf("largest line number == [%d]\n", max_line_number);
    printf("-----------------------------------------------------\n");
}

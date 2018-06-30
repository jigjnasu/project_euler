/*
  This is solution for problem 26 (Reciprocal cycles) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : October 10th, 2016
*/

#include "problem_26.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_26::Problem_26() {}

pp::Problem_26::~Problem_26() {}

void pp::Problem_26::reciprocal_cycles() const {
    int max_number = 0;
    int max_recurence = 0;
    std::string max_fraction;

    for (int i = 2; i < 1000; ++i) {
        const std::string str_fraction = m_fraction(1, i);
        const int count = m_get_max_recurence_count(str_fraction);
        if (count > max_recurence) {
            max_number = i;
            max_recurence = count;
            max_fraction = str_fraction;
        }
    }

    printf("---------------------------------------------------------------------------------------------------\n");
    printf("1 / [%d] has maximum recurence of [%d]\n", max_number, max_recurence);
    printf("fraction == [%s]\n", max_fraction.c_str());
    printf("---------------------------------------------------------------------------------------------------\n");
}

std::string pp::Problem_26::m_fraction(int x, int y) const {
    int counter = 1;
    x *= 10;
    std::vector<int> dictionary;
    dictionary.push_back(1);

    std::string result = "0.";

    while (1) {
        while (x < y) {
            x *= 10;
            ++counter;
            if (counter > 1) {
                dictionary.push_back(0);
                result += "0";
            }
        }
        counter = 0;

        const int remainder = x % y;
        result.push_back((x / y) + '0');

        if (remainder == 0)
            break;

        int pos = 0;
        // recurence case
        if (m_is_in_dictionary(dictionary, remainder, pos)) {
            result.insert(pos + 2, "(");
            result += ")";
            break;
        }

        dictionary.push_back(remainder);

        x = remainder;
    }

    return result;
}

bool pp::Problem_26::m_is_in_dictionary(const std::vector<int>& dictionary,
                                        int key, int pos) const {
    for (std::size_t i = 0; i < dictionary.size(); ++i) {
        if (key == dictionary[i]) {
            pos = i;
            return true;
        }
    }

    return false;
}

int pp::Problem_26::m_get_max_recurence_count(const std::string& number) const {
    std::size_t start_pos = number.find("(");
    if (start_pos == std::string::npos)
        return 0;

    return number.find(")") - start_pos;
}

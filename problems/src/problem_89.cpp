#include "problem_89.h"
#include <vector>
#include <cstdio>
#include <random>

namespace pp = project_euler::problems;

std::vector<std::string> ROMANS = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
std::vector<int> INTS = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

pp::Problem_89::Problem_89() {}

pp::Problem_89::~Problem_89() {}

void pp::Problem_89::roman_numbers() const {
    for (int i = 0; i < 100; ++i) {
        const int n = random(1, 1000);
        printf("[%8d] == [%20s]\n", n, roman(n).c_str());
    }
}

std::string pp::Problem_89::roman(int n) const {
    std::string res;
    for (std::size_t i = 0; i < INTS.size(); ++i) {
        while (n - INTS[i] >= 0) {
            n -= INTS[i];
            res += ROMANS[i];
        }
    }
    return res;
} 

int pp::Problem_89::random(int min, int max) const {
    std::random_device rd;
    std::uniform_int_distribution<> dt(min, max);
    return dt(rd);
}

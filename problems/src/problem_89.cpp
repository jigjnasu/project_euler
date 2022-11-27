#include "problem_89.h"
#include <vector>
#include <cstdio>
#include <random>
#include <fstream>
#include <unordered_map>

namespace pp = project_euler::problems;

std::vector<std::string> ROMANS = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
std::vector<int> INTS = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

std::unordered_map<char, int> DICT = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

pp::Problem_89::Problem_89() {}

pp::Problem_89::~Problem_89() {}

void pp::Problem_89::roman_numbers() const {
    // read the roman number file
    std::ifstream ifs("../data/p089_roman.txt");
    std::string line;
    while (std::getline(ifs, line))
        printf("[%20s] == [%8d]\n", line.c_str(), decimal(line));
    ifs.close();
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

int pp::Problem_89::decimal(const std::string& n) const {
    int res = 0;
    for (std::size_t i = 0; i < n.size(); ++i) {
        if (i + 1 < n.size() && DICT[n[i]] < DICT[i + 1])
            res += -1 * DICT[n[i]];
        else
            res += DICT[n[i]];
    }
    return res;
}

int pp::Problem_89::random(int min, int max) const {
    std::random_device rd;
    std::uniform_int_distribution<> dt(min, max);
    return dt(rd);
}

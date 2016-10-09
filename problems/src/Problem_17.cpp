#include "Problem_17.h"
#include <cstdio>

namespace pp = project_euler::problems;

const std::string DICTIONARY_A[] = {"one", "two", "three", "four", "five",
                                    "six", "seven", "eight", "nine", "ten"};
const std::string DICTIONARY_B[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                    "sixteen", "seventeen", "eighteen", "nineteen"};
const std::string DICTIONARY_C[] = {"twenty", "thirty", "forty", "fifty", "sixty",
                                    "seventy", "eighty", "ninety"};

pp::Problem_17::Problem_17() {}

pp::Problem_17::~Problem_17() {}

void pp::Problem_17::letter_count() const {
    std::size_t count = 0;
    for (int i = 1; i <= 1000; ++i)
        count += m_count(i).size();
    printf("Letter count from 1 to 1000 == [%lu]\n", count);
}

std::string pp::Problem_17::m_count(int n) const {
    std::string word;

    if (n >= 1 && n <= 10) {
        word += DICTIONARY_A[n - 1];
    } else if (n >= 11 && n <= 19) {
        word += DICTIONARY_B[n - 11];
    } else if (n >= 20 && n <= 99) {
        word += DICTIONARY_C[(n / 10) - 2];
        n %= 10;
        if (n)
            word += DICTIONARY_A[n - 1];		
    } else if (n >= 100 && n <= 999){
        word += DICTIONARY_A[(n / 100) - 1] + "hundred";
        n %= 100;
        if (n) {
            word += "and";
            word += m_count(n);
        }
    } else {
        word += "onethousand";
    }

    return word;
}

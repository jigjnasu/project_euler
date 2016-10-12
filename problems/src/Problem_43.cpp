
#include "Problem_43.h"
#include "Integer.h"
#include "PermutationGenerator.h"
#include <vector>
#include <cstdio>
#include <cstdlib>

namespace pp = project_euler::problems;

pp::Problem_43::Problem_43() {}

pp::Problem_43::~Problem_43() {}

void pp::Problem_43::sub_string_divisiblity() const {
    std::vector<std::string> permutations;
    utility::integer::Integer sum;
    utility::permutation_generator::PermutationGenerator<int> generator(10, true);
    generator.Generate();
    generator.Result(permutations);

    for (std::size_t i = 0; i < permutations.size(); ++i)
        if (m_is_sub_string_divisible(permutations[i]))
            sum += permutations[i];
        
    printf("Sum of all sub string divisibles === ");
    sum.Print();
    printf("\n");    
}

bool pp::Problem_43::m_is_sub_string_divisible(const std::string& number) const {
    if (std::atoi(number.substr(1, 3).c_str()) % 2  ||
        std::atoi(number.substr(2, 3).c_str()) % 3  ||
        std::atoi(number.substr(3, 3).c_str()) % 5  ||
        std::atoi(number.substr(4, 3).c_str()) % 7  ||
        std::atoi(number.substr(5, 3).c_str()) % 11 ||
        std::atoi(number.substr(6, 3).c_str()) % 13 ||
        std::atoi(number.substr(7, 3).c_str()) % 17)
        return false;
    return true;    
}

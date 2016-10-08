#include "common/Integer.h"
#include "common/PermutationGenerator.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

bool is_sub_string_divisible(const std::string& number) {
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

void sub_string_divisibility() {
    std::vector<std::string> permutations;
    PROJECT_EULER::COMMON::Integer sum;
    PROJECT_EULER::COMMON::PermutationGenerator<int> generator(10, true);
    generator.Generate();
    generator.Result(permutations);

    for (std::size_t i = 0; i < permutations.size(); ++i)
        if (is_sub_string_divisible(permutations[i]))
            sum += permutations[i];
        
    printf("Sum of all sub string divisibles === ");
    sum.Print();
    printf("\n");
}


int main() {
    std::clock_t start = clock();
    sub_string_divisibility();
    printf("Execution time == [%f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
	
    return 0;
}

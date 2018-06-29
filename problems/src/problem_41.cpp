#include "Problem_41.h"
#include "PermutationGenerator.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_41::Problem_41() {}

pp::Problem_41::~Problem_41() {}

void pp::Problem_41::pandigital_prime() const {
    utility::permutation_generator::PermutationGenerator<int> generator(7, false);
    generator.Generate();

    std::vector<int> permutations;
    generator.Result(permutations);

    utility::maths::Maths<std::size_t> math;
    int largest_prime_number = 0;
    
    for (std::size_t i = 0; i < permutations.size(); ++i)
        if (math.is_prime(permutations[i]))
            if (permutations[i] > largest_prime_number)
                largest_prime_number = permutations[i];

    printf("Largest pan digital number == [%d]\n", largest_prime_number);
}

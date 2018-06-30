#include "problem_37.h"
#include "common.h"
#include "maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_37::Problem_37() {}

pp::Problem_37::~Problem_37() {}

void pp::Problem_37::truncatable_primes() const {
    utility::common::Common<int> common;
    int sum = 0;
    int iter = 10;
    int counter = 0;
    while (counter < 11) {
        if (m_is_trunctable_prime(common.to_string(iter))) {
            sum += iter;
            ++counter;
        }
        ++iter;
    }

    printf("Sum of 11 truncatable primes == [%d]\n", sum);
}

bool pp::Problem_37::m_is_trunctable_prime(const std::string& number) const {
    utility::maths::Maths<int> math;
    utility::common::Common<int> common;
    if (!math.is_prime(common.to_number(number)))
        return false;

    for (std::size_t i = 1; i < number.size(); ++i)
        if (!math.is_prime(common.to_number(number.substr(0, i).c_str())))
            return false;

    for (std::size_t i = number.size() - 1; i >= 1; --i)
        if (!math.is_prime(common.to_number(number.substr(i, number.size() - i).c_str())))
            return false;

    return true;
}

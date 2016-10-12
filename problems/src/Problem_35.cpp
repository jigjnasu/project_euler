#include "Problem_35.h"
#include "Maths.h"
#include "Common.h"
#include <cstdio>
#include <cstdlib>

namespace pp = project_euler::problems;

pp::Problem_35::Problem_35() {}

pp::Problem_35::~Problem_35() {}

void pp::Problem_35::circular_primes() const {
    utility::common::Common<int> common;
    int counter = 0;
    for (int i = 2; i < 1000000; ++i)
        if (m_is_circular_prime(common.to_string(i)))
            ++counter;

    printf("Circular primes under million == [%d]\n", counter);    
}

void pp::Problem_35::m_rotate_left(std::string& number) const {
    number.push_back(number[0]);
    number.erase(number.begin());
}

bool pp::Problem_35::m_is_circular_prime(std::string number) const {
    utility::maths::Maths<int> math;
    utility::common::Common<int> common;
    for (std::size_t i = 0; i < number.size(); ++i) {
        if (!math.is_prime(common.to_number(number)))
            return false;
        m_rotate_left(number);
    }

    return true;    
}

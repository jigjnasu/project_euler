#include "Problem_80.h"
#include "Maths.h"
#include "Integer.h"
#include <string>
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_80::Problem_80() {}

pp::Problem_80::~Problem_80() {}

void pp::Problem_80::square_root_digital_expansion() const {
    // Find the first 100 digit sum of irrational numbers.
    int sum = 0;
    for (int n = 2; n < 100; ++n)
        sum += m_square_root_sum(n);
    
    printf("-----------------------------------------------------------------------\n");
    printf("Total sum of all digits of square root of irrational numbers == [%d]\n", sum);
    printf("-----------------------------------------------------------------------\n");    
}

int pp::Problem_80::m_square_root_sum(int n) const {
    utility::maths::Maths<int> maths;
    if (maths.is_perfect_square(n))
        return 0;

    int limit = 100;
    const std::string number = maths.square_root(n, limit);
    printf("n == [%2d] || size == [%lu] --> [%s]\n", n, number.size(), number.c_str());
    int sum = number[0] - '0';
    for (std::size_t i = 2; i < number.size(); ++i)
        sum += number[i] - '0';
    
    return sum;
}

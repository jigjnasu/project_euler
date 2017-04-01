#include "Problem_248.h"
#include "Maths.h"

project_euler::problems::Problem_248::Problem_248() {}

project_euler::problems::Problem_248::~Problem_248() {}

void project_euler::problems::Problem_248::totient() const {
    utility::maths::Maths<std::size_t> maths;
    const std::size_t number = maths.factorial(13);

    std::size_t n = 2;
    std::vector<std::size_t> factors;
    while (factors.size() != 150000) {
        if (m_gcd(number, n) == 1)
            factors.push_back(n);
        ++n;
    }

    for (std::size_t i = 0; i < factors.size(); ++i)
        printf("%lu ", factors[i]);
    printf("\n");
}

std::size_t project_euler::problems::Problem_248::m_gcd(std::size_t a, std::size_t b) const {
    while (b && a % b != 0) {
        const std::size_t t = a;
        a = b;
        b = t / b;
    }

    return b;
}

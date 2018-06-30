#include "problem_25.h"
#include "maths.h"
#include "integer.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_25::Problem_25() {}

pp::Problem_25::~Problem_25() {}

void pp::Problem_25::fibonacci() const {
    utility::maths::Maths<utility::integer::Integer> maths;
    std::size_t index = 1;
    while (maths.fibonacci(index++).size() < 1000);

    printf("Index == [%lu]\n", index - 1);
}

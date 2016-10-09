#include "Problem_25.h"
#include "Maths.h"
#include "Integer.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_25::Problem_25() {}

pp::Problem_25::~Problem_25() {}

void pp::Problem_25::fibonacci() const {
    utility::maths::Maths<utility::integer::Integer> maths;
    std::size_t index = 1;
    while (maths.fibonacci(index++).Size() < 1000);

    printf("Index == [%lu]\n", index - 1);
}

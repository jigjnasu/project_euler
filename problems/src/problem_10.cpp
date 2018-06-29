#include "Problem_10.h"
#include "Integer.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_10::Problem_10() {}

pp::Problem_10::~Problem_10() {}

void pp::Problem_10::sum_of_primes() const {
    utility::maths::Maths<int> math;
    utility::integer::Integer sum(0);
    for (int i = 2; i < 2000000; ++i)
	if (math.is_prime(i))
	    sum += i;

    sum.print();
}

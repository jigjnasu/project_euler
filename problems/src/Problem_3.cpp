#include "Problem_3.h"
#include "Maths.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_3::Problem_3() {}

pp::Problem_3::~Problem_3() {}

void pp::Problem_3::largest_factor(const u_long& n) const {
    utility::maths::Maths<u_long> math;
    for (u_long i = std::sqrt(n); i >= 2; --i) {
	if (n % i == 0) {
	    if (math.is_prime(i)) {
		printf("largest factor == [%llu]\n", i);
		break;
	    }
	}
    }    
}

#include "problem_65.h"
#include "integer.h"
#include "string.h"
#include <cstdio>

/*
  To calculate contined fraction for e
  We have a series which has a unique pattern when it is divisible of 3 it is a (n / 3) * 2
  else 1.

  Now we have an = (in % 3) == 0 ? (i / 3) * 2 ? 1;

  According to the formula we can form e continued fraction like.
  numerator  (p) = an (pn - 1) + pn - 2
  denomiator (q) = an (qn - 1) + qn - 2;

  But here we just need to calculate numerator we will only calculate that.

  Let's formula is
  an = an * n1 + n2
 */

namespace pp = project_euler::problems;

pp::Problem_65::Problem_65() {}

pp::Problem_65::~Problem_65() {}

void pp::Problem_65::convergents_of_e() const {
    const int limit = 100;
    utility::integer::Integer n2 = 1;
    utility::integer::Integer n1 = 1;
    utility::integer::Integer n  = 0;

    for (int i = 1; i <= limit; ++i) {
        const int a = (i % 3 == 0) ? (i / 3) * 2 : 1;
        n = (n1 * a) + n2;
        n2 = n1;
        n1 = n;
    }

    utility::string::String<int> str;
    printf("Sum of [%d]th convergent number of e == [%d]\n", limit, str.sum_of_digits(n.get()));
}

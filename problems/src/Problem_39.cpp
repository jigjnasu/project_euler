/*
  This is solution for problem 39 (Integer right triangles) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "Problem_39.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_39::Problem_39() {}

pp::Problem_39::~Problem_39() {}

void pp::Problem_39::integer_right_triangles() const {
    int max_p = 0;
    int max_count = 0;
    for (int p = 1; p <= 1000; ++p) {
        int counter = 0;
        for (int a = 1; a <= p / 3; ++a) {
            for (int b = 1; b <= p / 2; ++b) {
                const int c = p - (a + b);
                if ((c * c) == (a * a) + (b * b))
                    ++counter;
            }
        }
        if (counter > max_count) {
            max_p = p;
            max_count = counter;
        }
    }

    printf("Max p with right angled triangles == [%d]\n", max_p);    
}

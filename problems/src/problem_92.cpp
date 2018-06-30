/*
  This is solution for problem 92 (Square digit chains) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 2nd, 2016
*/

#include "problem_92.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_92::Problem_92() {}

pp::Problem_92::~Problem_92() {}

void pp::Problem_92::square_digit_chains() const {
    const int max = 10000000;
    const int size = 10000;
    int dictionary[size] = {0};

    int counter = 0;
    for (int i = 1; i < max; ++i) {
        int number = i;
        while (1) {
            number = m_get_square_digit(number);

            if (dictionary[number] == 1)
                break;
            if (dictionary[number] == 89) {
                ++counter;
                break;
            }

            if (number == 1) {
                if (i < size)
                    dictionary[i] = 1;
                break;
            }

            if (number == 89) {
                if (i < size)
                    dictionary[i] = 89;
                ++counter;
                break;
            }
        }
    }

    printf("-----------------------------------------------------------------\n");
    printf("Number of Square Digit Chains ending at 89 == [%d]\n", counter);
    printf("-----------------------------------------------------------------\n");
}

int pp::Problem_92::m_get_square_digit(int n) const {
    int square_sum = 0;
    while (n) {
        const int t = n % 10;
        square_sum += (t * t);
        n /= 10;
    }

    return square_sum;    
}

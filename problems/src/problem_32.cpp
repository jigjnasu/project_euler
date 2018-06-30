/*
  This is solution for problem 32 (Pandigital products) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 18th, 2016
*/

#include "problem_32.h"
#include <cstdio>
#include <set>

namespace pp = project_euler::problems;

pp::Problem_32::Problem_32() {}

pp::Problem_32::~Problem_32() {}

void pp::Problem_32::pandigital_product() const {
    std::set<int> products;
    for (int i = 1; i < 100; ++i) {
        for (int j = 100; j < 2000; ++j) {
            if (m_is_pandigital(i, j, i * j))
                products.insert(i * j);
        }
    }

    int product_sum = 0;
    for (std::set<int>::const_iterator it = products.begin(); it != products.end(); ++it)
        product_sum += *it;

    printf("Product sum of all pandigital numbers == [%d]\n", product_sum);
}

bool pp::Problem_32::m_is_pandigital(int a, int b, int c) const {
    int array[9] = {0};

    while (a) {
        const int value = a % 10;
        if (array[value - 1])
            return false;
        else
            array[value - 1] = 1;
        a /= 10;
    }

    while (b) {
        const int value = b % 10;
        if (array[value - 1])
            return false;
        else
            array[value - 1] = 1;
        b /= 10;
    }

    while (c) {
        const int value = c % 10;
        if (array[value - 1])
            return false;
        else
            array[value - 1] = 1;
        c /= 10;
    }

    for (int i = 0; i < 9; ++i)
        if (array[i] == 0)
            return false;

    return true;
}

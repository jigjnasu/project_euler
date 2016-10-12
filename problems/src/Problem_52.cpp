/*
  This is solution for problem 52 (Permuted multiples) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 13th, 2016
*/

#include "Problem_52.h"
#include "QuickSort.h"
#include "Common.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_52::Problem_52() {}

pp::Problem_52::~Problem_52() {}

void pp::Problem_52::permutated_multiples() const {
    int i = 2;
    utility::common::Common<int> common;
    
    while (!m_all_permutated(common.to_string(i * 1),
                             common.to_string(i * 2),
                             common.to_string(i * 3),
                             common.to_string(i * 4),
                             common.to_string(i * 5),
                             common.to_string(i * 6))) {
        ++i; 
    }

    printf("1 * %d == [%d]\n", i, i * 1);
    printf("2 * %d == [%d]\n", i, i * 2);
    printf("3 * %d == [%d]\n", i, i * 3);
    printf("4 * %d == [%d]\n", i, i * 4);
    printf("5 * %d == [%d]\n", i, i * 5);
    printf("6 * %d == [%d]\n", i, i * 6);
}

bool pp::Problem_52::m_all_permutated(std::string x1, std::string x2,
                                      std::string x3, std::string x4,
                                      std::string x5, std::string x6) const {
    if (x1.size() != x2.size() ||
        x1.size() != x3.size() ||
        x1.size() != x4.size() ||
        x1.size() != x5.size() ||
        x1.size() != x6.size())
        return false;

    utility::algorithms::sort::QuickSort<char> quick_sort;
    quick_sort.sort(x1);
    quick_sort.sort(x2);
    quick_sort.sort(x3);
    quick_sort.sort(x4);
    quick_sort.sort(x5);
    quick_sort.sort(x6);

    for (std::size_t i = 0; i < x1.size(); ++i)
        if (x1[i] != x2[i] || x1[i] != x3[i] || x1[i] != x4[i] || x1[i] != x5[i] || x1[i] != x6[i])
            return false;
    return true;
}

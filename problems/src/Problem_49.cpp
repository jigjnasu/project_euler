/*
  This is solution for problem 49 (Prime Permutations) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : May 12th, 2016
*/

#include "Problem_49.h"
#include "QuickSort.h"
#include "Maths.h"
#include "Common.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_49::Problem_49() {}

pp::Problem_49::~Problem_49() {}

void pp::Problem_49::prime_permutations() const {
    utility::maths::Maths<int> math;
    utility::common::Common<int> common;
    const int start_number = 1000;
    const int end_number = 9999;

    for (int i = start_number; i <= end_number; ++i) {
        if (math.is_prime(i)) {
            for (int j = i + 1; j <= end_number; ++j) {
                if (math.is_prime(j)) {
                    const int k = j + (j - i);
                    if (k <= end_number && math.is_prime(k)) {
                        const std::string a = common.to_string(i);
                        const std::string b = common.to_string(j);
                        const std::string c = common.to_string(k);

                        if (m_is_permutation(a, b, c)) {
                            printf("prime permutations == [%s]\n", std::string(a + b + c).c_str());
                        }
                    }
                }
            }
        }
    }    
}

bool pp::Problem_49::m_is_permutation(std::string a, std::string b, std::string c) const {
    utility::algorithms::sort::QuickSort<char> quick_sort;
    quick_sort.sort(a);
    quick_sort.sort(b);
    quick_sort.sort(c);

    for (std::size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i] || a[i] != c[i])
            return false;
    return true;
}

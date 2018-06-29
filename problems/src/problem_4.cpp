#include "Problem_4.h"
#include "Common.h"
#include <cstdio>

namespace pp = project_euler::problems;
namespace uc = utility::common;

pp::Problem_4::Problem_4() {}

pp::Problem_4::~Problem_4() {}

void pp::Problem_4::largest_palindrome_product() const {
    uc::Common<int> common;
    int largest = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            const int product = i * j;
            if (common.is_palindrome(common.to_string(product)))
                if (product > largest)
                    largest = product;
        }
    }

    printf("largest palindrome product of 3 digit == [%d]\n", largest);
}

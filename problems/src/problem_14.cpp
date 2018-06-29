#include "Problem_14.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_14::Problem_14() {}

pp::Problem_14::~Problem_14() {}

void pp::Problem_14::collatz_sequence() const {
    u_l number = 0;
    int longest_chain = 0;
    for (u_l i = 2; i < 1000000; ++i) {
        const int sequence = m_sequence_chain(i);

        if (sequence > longest_chain) {
            longest_chain = sequence;
            number = i;
        }
    }

    printf("[%llu] has longest collatz sequence of [%d] elements\n", number, longest_chain);
}

int pp::Problem_14::m_sequence_chain(u_l n) const {
    int counter = 1;
    while (n != 1) {
        ++counter;
        if (n % 2)
            n = (3 * n) + 1;
        else
            n /= 2;
    }

    return counter;
}

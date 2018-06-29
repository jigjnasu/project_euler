#include "Problem_24.h"

const int SIZE = 10;

namespace pp = project_euler::problems;

pp::Problem_24::Problem_24() {}

pp::Problem_24::~Problem_24() {}

void pp::Problem_24::permutation_generator() const {
    int V[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
    for (int i = 1; i < 1000000 ; ++i)
        m_get_next<SIZE>(V);
    m_print<SIZE>(V);    
}

template <std::size_t size>
void pp::Problem_24::m_get_next(int (&A)[size]) const {
    int i = size -1;
    while (A[i - 1] >= A[i])
        --i;

    int j = size;
    while (A[j -1] <= A[i -1])
        --j;

    m_swap(A[i - 1], A[j - 1]);

    ++i;
    j = size;
    while (i < j) {
        m_swap(A[i - 1], A[j - 1]);
        ++i;
        --j;
    }    
}

template <std::size_t size>
void pp::Problem_24::m_print(const int (&V)[size]) const {
    for (std::size_t i = 0; i < size; ++i)
        printf("%d", V[i]);
    printf("\n");    
}

void pp::Problem_24::m_swap(int& A, int& B) const {
    A ^= B;
    B ^= A;
    A ^= B;
}

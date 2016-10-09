#include "Problem_1.h"
#include "Problem_2.h"
#include "Problem_3.h"
#include "Problem_4.h"
#include "Problem_5.h"
#include "Problem_6.h"
#include "Problem_7.h"
#include "Problem_8.h"
#include "Problem_9.h"
#include "Problem_10.h"
#include "Problem_11.h"
#include "Problem_12.h"
#include "Problem_13.h"
#include "Problem_14.h"
#include "Problem_16.h"
#include "Problem_17.h"
#include "Problem_19.h"
#include "Problem_20.h"
#include "Problem_21.h"
#include "Problem_22.h"
#include "Problem_23.h"
#include "Problem_24.h"
#include "Problem_25.h"
#include "Problem_26.h"
#include "Problem_27.h"
#include "Problem_29.h"
#include "Problem_30.h"
#include <cstdio>
#include <ctime>

namespace pp = project_euler::problems;

void test_case_for_problem_1() {
    const std::clock_t start = clock();
    
    pp::Problem_1 problem;
    const int N = 999;
    printf("Sum == [%d]\n", (problem.sum(3, N) + problem.sum(5, N)) - problem.sum(15, N));

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_2() {
    const std::clock_t start = clock();
    
    pp::Problem_2 problem;
    printf("Sum of even fibbonacci numbers == [%d]\n", problem.sum());

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");        
}

void test_case_for_problem_3() {
    const std::clock_t start = clock();
    
    pp::Problem_3 problem;
    problem.largest_factor(600851475143);

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_4() {
    const std::clock_t start = clock();
    
    pp::Problem_4 problem;
    problem.largest_palindrome_product();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_5() {
    const std::clock_t start = clock();
    
    pp::Problem_5 problem;
    problem.smallest_multiple(20);

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_6() {
    const std::clock_t start = clock();
    
    pp::Problem_6 problem;
    problem.sum_of_squares(100);

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_7() {
    const std::clock_t start = clock();
    
    pp::Problem_7 problem;
    problem.prime_number(10001);

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_8() {
    const std::clock_t start = clock();
    
    pp::Problem_8 problem;
    problem.series_product("../data/largest_product.txt");

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_9() {
    const std::clock_t start = clock();
    
    pp::Problem_9 problem;
    problem.special_triplet();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_10() {
    const std::clock_t start = clock();
    
    pp::Problem_10 problem;
    problem.sum_of_primes();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_11() {
    const std::clock_t start = clock();
    
    pp::Problem_11 problem;
    problem.largest_product("../data/largest_product_in_a_grid.txt");

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_12() {
    const std::clock_t start = clock();
    
    pp::Problem_12 problem;
    problem.max_divisible_triangular_number();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_13() {
    const std::clock_t start = clock();
    
    pp::Problem_13 problem;
    problem.large_sum("../data/large_sum.txt");

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_14() {
    const std::clock_t start = clock();
    
    pp::Problem_14 problem;
    problem.collatz_sequence();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_16() {
    const std::clock_t start = clock();
    
    pp::Problem_16 problem;
    problem.sum();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_17() {
    const std::clock_t start = clock();
    
    pp::Problem_17 problem;
    problem.letter_count();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_19() {
    const std::clock_t start = clock();
    
    pp::Problem_19 problem;
    problem.sundays();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_20() {
    const std::clock_t start = clock();
    
    pp::Problem_20 problem;
    problem.sum_of_factorial_digits(100);

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_21() {
    const std::clock_t start = clock();
    
    pp::Problem_21 problem;
    problem.sum_of_amicable_numbers();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_22() {
    const std::clock_t start = clock();
    
    pp::Problem_22 problem;
    problem.names_scores("../data/names.txt");

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_23() {
    const std::clock_t start = clock();
    
    pp::Problem_23 problem;
    problem.non_abundant_sums();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_24() {
    const std::clock_t start = clock();
    
    pp::Problem_24 problem;
    problem.permutation_generator();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_25() {
    const std::clock_t start = clock();
    
    pp::Problem_25 problem;
    problem.fibonacci();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_26() {
    const std::clock_t start = clock();
    
    pp::Problem_26 problem;
    problem.reciprocal_cycles();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_27() {
    const std::clock_t start = clock();
    
    pp::Problem_27 problem;
    problem.quadratic_primes();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_29() {
    const std::clock_t start = clock();
    
    pp::Problem_29 problem;
    problem.distinct_powers();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_30() {
    const std::clock_t start = clock();
    
    pp::Problem_30 problem;
    problem.digit_fifth_power();

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

int main() {
    printf("------------------------------------- Problem 1 ----------------------------------------\n");
    test_case_for_problem_1();
    printf("------------------------------------- Problem 2 ----------------------------------------\n");    
    test_case_for_problem_2();
    printf("------------------------------------- Problem 3 ----------------------------------------\n");    
    test_case_for_problem_3();
    printf("------------------------------------- Problem 4 ----------------------------------------\n");    
    test_case_for_problem_4();
    printf("------------------------------------- Problem 5 ----------------------------------------\n");    
    test_case_for_problem_5();
    printf("------------------------------------- Problem 6 ----------------------------------------\n");    
    test_case_for_problem_6();
    printf("------------------------------------- Problem 7 ----------------------------------------\n");    
    test_case_for_problem_7();
    printf("------------------------------------- Problem 8 ----------------------------------------\n");    
    test_case_for_problem_8();
    printf("------------------------------------- Problem 9 ----------------------------------------\n");    
    test_case_for_problem_9();
    printf("------------------------------------- Problem 10 ---------------------------------------\n");    
    test_case_for_problem_10();
    printf("------------------------------------- Problem 11 ---------------------------------------\n");    
    test_case_for_problem_11();
    printf("------------------------------------- Problem 12 ---------------------------------------\n");    
    test_case_for_problem_12();
    printf("------------------------------------- Problem 13 ---------------------------------------\n");    
    test_case_for_problem_13();
    printf("------------------------------------- Problem 14 ---------------------------------------\n");    
    test_case_for_problem_14();
    printf("------------------------------------- Problem 16 ---------------------------------------\n");    
    test_case_for_problem_16();
    printf("------------------------------------- Problem 17 ---------------------------------------\n");    
    test_case_for_problem_17();
    printf("------------------------------------- Problem 19 ---------------------------------------\n");    
    test_case_for_problem_19();
    printf("------------------------------------- Problem 20 ---------------------------------------\n");    
    test_case_for_problem_20();
    printf("------------------------------------- Problem 21 ---------------------------------------\n");    
    test_case_for_problem_21();
    printf("------------------------------------- Problem 22 ---------------------------------------\n");    
    test_case_for_problem_22();
    printf("------------------------------------- Problem 23 ---------------------------------------\n");    
    test_case_for_problem_23();
    printf("------------------------------------- Problem 24 ---------------------------------------\n");    
    test_case_for_problem_24();
    printf("------------------------------------- Problem 25 ---------------------------------------\n");    
    test_case_for_problem_25();
    printf("------------------------------------- Problem 26 ---------------------------------------\n");    
    test_case_for_problem_26();
    printf("------------------------------------- Problem 27 ---------------------------------------\n");    
    test_case_for_problem_27();
    printf("------------------------------------- Problem 29 ---------------------------------------\n");    
    test_case_for_problem_29();
    printf("------------------------------------- Problem 30 ---------------------------------------\n");    
    test_case_for_problem_30();
    
    return 0;
}

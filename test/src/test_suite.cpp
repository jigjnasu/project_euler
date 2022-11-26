/*
  Test suite for all the Project Euler problems.
  Can run single test case by providing the problem number.
  Can run all the test cases one by one in ascending order.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 17th, 2016
 */

#include "test_suite.h"
#include "all_problem_headers.h"
#include <cstdio>

const int min = 1;
const int max = 525;

namespace pt = project_euler::test;
namespace pp = project_euler::problems;

pt::TestSuite::TestSuite() : m_test_case(0) {
    m_initialize_test_cases_dictionary();
}

pt::TestSuite::~TestSuite() {}

void pt::TestSuite::run(int test_case) {
    ptrFunc function = m_test_cases_dictionary[test_case];
    if (function) {
        m_test_case = test_case;
        m_execute(function);
    }
}

void pt::TestSuite::run_all() {
    for (int i = min; i <= max; ++i) {
        ptrFunc function = m_test_cases_dictionary[i];
        if (function) {
            m_test_case = i;
            m_execute(function);
        }
    }
}

void pt::TestSuite::m_initialize_test_cases_dictionary() {
    m_test_cases_dictionary[1]   = &TestSuite::m_test_case_for_problem_1;
    m_test_cases_dictionary[2]   = &TestSuite::m_test_case_for_problem_2;
    m_test_cases_dictionary[3]   = &TestSuite::m_test_case_for_problem_3;
    m_test_cases_dictionary[4]   = &TestSuite::m_test_case_for_problem_4;
    m_test_cases_dictionary[5]   = &TestSuite::m_test_case_for_problem_5;
    m_test_cases_dictionary[6]   = &TestSuite::m_test_case_for_problem_6;
    m_test_cases_dictionary[7]   = &TestSuite::m_test_case_for_problem_7;
    m_test_cases_dictionary[8]   = &TestSuite::m_test_case_for_problem_8;
    m_test_cases_dictionary[9]   = &TestSuite::m_test_case_for_problem_9;
    m_test_cases_dictionary[10]  = &TestSuite::m_test_case_for_problem_10;
    m_test_cases_dictionary[11]  = &TestSuite::m_test_case_for_problem_11;
    m_test_cases_dictionary[12]  = &TestSuite::m_test_case_for_problem_12;
    m_test_cases_dictionary[13]  = &TestSuite::m_test_case_for_problem_13;
    m_test_cases_dictionary[14]  = &TestSuite::m_test_case_for_problem_14;
    m_test_cases_dictionary[15]  = &TestSuite::m_test_case_for_problem_15;
    m_test_cases_dictionary[16]  = &TestSuite::m_test_case_for_problem_16;
    m_test_cases_dictionary[17]  = &TestSuite::m_test_case_for_problem_17;
    m_test_cases_dictionary[18]  = &TestSuite::m_test_case_for_problem_18;
    m_test_cases_dictionary[19]  = &TestSuite::m_test_case_for_problem_19;
    m_test_cases_dictionary[20]  = &TestSuite::m_test_case_for_problem_20;
    m_test_cases_dictionary[21]  = &TestSuite::m_test_case_for_problem_21;
    m_test_cases_dictionary[22]  = &TestSuite::m_test_case_for_problem_22;
    m_test_cases_dictionary[23]  = &TestSuite::m_test_case_for_problem_23;
    m_test_cases_dictionary[24]  = &TestSuite::m_test_case_for_problem_24;
    m_test_cases_dictionary[25]  = &TestSuite::m_test_case_for_problem_25;
    m_test_cases_dictionary[26]  = &TestSuite::m_test_case_for_problem_26;
    m_test_cases_dictionary[27]  = &TestSuite::m_test_case_for_problem_27;
    m_test_cases_dictionary[28]  = &TestSuite::m_test_case_for_problem_28;
    m_test_cases_dictionary[29]  = &TestSuite::m_test_case_for_problem_29;
    m_test_cases_dictionary[30]  = &TestSuite::m_test_case_for_problem_30;
    m_test_cases_dictionary[31]  = &TestSuite::m_test_case_for_problem_31;
    m_test_cases_dictionary[32]  = &TestSuite::m_test_case_for_problem_32;
    m_test_cases_dictionary[33]  = &TestSuite::m_test_case_for_problem_33;
    m_test_cases_dictionary[34]  = &TestSuite::m_test_case_for_problem_34;
    m_test_cases_dictionary[35]  = &TestSuite::m_test_case_for_problem_35;
    m_test_cases_dictionary[36]  = &TestSuite::m_test_case_for_problem_36;
    m_test_cases_dictionary[37]  = &TestSuite::m_test_case_for_problem_37;
    m_test_cases_dictionary[38]  = &TestSuite::m_test_case_for_problem_38;
    m_test_cases_dictionary[39]  = &TestSuite::m_test_case_for_problem_39;
    m_test_cases_dictionary[40]  = &TestSuite::m_test_case_for_problem_40;
    m_test_cases_dictionary[41]  = &TestSuite::m_test_case_for_problem_41;
    m_test_cases_dictionary[42]  = &TestSuite::m_test_case_for_problem_42;
    m_test_cases_dictionary[43]  = &TestSuite::m_test_case_for_problem_43;
    m_test_cases_dictionary[44]  = &TestSuite::m_test_case_for_problem_44;
    m_test_cases_dictionary[45]  = &TestSuite::m_test_case_for_problem_45;
    m_test_cases_dictionary[46]  = &TestSuite::m_test_case_for_problem_46;
    m_test_cases_dictionary[47]  = &TestSuite::m_test_case_for_problem_47;
    m_test_cases_dictionary[48]  = &TestSuite::m_test_case_for_problem_48;
    m_test_cases_dictionary[49]  = &TestSuite::m_test_case_for_problem_49;
    m_test_cases_dictionary[50]  = &TestSuite::m_test_case_for_problem_50;
    m_test_cases_dictionary[52]  = &TestSuite::m_test_case_for_problem_52;
    m_test_cases_dictionary[53]  = &TestSuite::m_test_case_for_problem_53;
    m_test_cases_dictionary[54]  = &TestSuite::m_test_case_for_problem_54;
    m_test_cases_dictionary[55]  = &TestSuite::m_test_case_for_problem_55;
    m_test_cases_dictionary[56]  = &TestSuite::m_test_case_for_problem_56;
    m_test_cases_dictionary[57]  = &TestSuite::m_test_case_for_problem_57;
    m_test_cases_dictionary[58]  = &TestSuite::m_test_case_for_problem_58;
    m_test_cases_dictionary[59]  = &TestSuite::m_test_case_for_problem_59;
    m_test_cases_dictionary[60]  = &TestSuite::m_test_case_for_problem_60;
    m_test_cases_dictionary[63]  = &TestSuite::m_test_case_for_problem_63;
    m_test_cases_dictionary[64]  = &TestSuite::m_test_case_for_problem_64;
    m_test_cases_dictionary[65]  = &TestSuite::m_test_case_for_problem_65;
    m_test_cases_dictionary[67]  = &TestSuite::m_test_case_for_problem_67;
    m_test_cases_dictionary[69]  = &TestSuite::m_test_case_for_problem_69;
    m_test_cases_dictionary[70]  = &TestSuite::m_test_case_for_problem_70;
    m_test_cases_dictionary[71]  = &TestSuite::m_test_case_for_problem_71;
    m_test_cases_dictionary[72]  = &TestSuite::m_test_case_for_problem_72;
    m_test_cases_dictionary[73]  = &TestSuite::m_test_case_for_problem_73;
    m_test_cases_dictionary[74]  = &TestSuite::m_test_case_for_problem_74;
    m_test_cases_dictionary[76]  = &TestSuite::m_test_case_for_problem_76;
    m_test_cases_dictionary[80]  = &TestSuite::m_test_case_for_problem_80;
    m_test_cases_dictionary[89]  = &TestSuite::m_test_case_for_problem_89;
    m_test_cases_dictionary[92]  = &TestSuite::m_test_case_for_problem_92;
    m_test_cases_dictionary[97]  = &TestSuite::m_test_case_for_problem_97;
    m_test_cases_dictionary[99]  = &TestSuite::m_test_case_for_problem_99;
    m_test_cases_dictionary[125] = &TestSuite::m_test_case_for_problem_125;
    m_test_cases_dictionary[145] = &TestSuite::m_test_case_for_problem_145;
    m_test_cases_dictionary[187] = &TestSuite::m_test_case_for_problem_187;
    m_test_cases_dictionary[206] = &TestSuite::m_test_case_for_problem_206;
    m_test_cases_dictionary[214] = &TestSuite::m_test_case_for_problem_214;
    m_test_cases_dictionary[297] = &TestSuite::m_test_case_for_problem_297;
}

void pt::TestSuite::m_execute(ptrFunc function) {
    (*this.*function)();
}

void pt::TestSuite::m_start_timer() {
    m_start_time = std::chrono::steady_clock::now();
}

void pt::TestSuite::m_end_timer() const {
    printf("----------------------------------------------------------------------------\n");
    printf("Execution time == [%16lf] seconds\n",
           std::chrono::duration<double>(std::chrono::steady_clock::now() - m_start_time).count());
    printf("----------------------------------------------------------------------------\n");
}

void pt::TestSuite::m_test_case_banner() const {
    printf("-------------------------------- Problem %5d ------------------------------\n",
           m_test_case);
}

void pt::TestSuite::m_test_case_for_problem_1() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_1 problem;
    const int N = 999;
    printf("Sum == [%d]\n", (problem.sum(3, N) + problem.sum(5, N)) - problem.sum(15, N));

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_2() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_2 problem;
    printf("Sum of even fibbonacci numbers == [%d]\n", problem.sum());

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_3() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_3 problem;
    problem.largest_factor(600851475143);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_4() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_4 problem;
    problem.largest_palindrome_product();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_5() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_5 problem;
    problem.smallest_multiple(20);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_6() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_6 problem;
    problem.sum_of_squares(100);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_7() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_7 problem;
    problem.prime_number(10001);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_8() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_8 problem;
    problem.series_product("../data/largest_product.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_9() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_9 problem;
    problem.special_triplet();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_10() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_10 problem;
    problem.sum_of_primes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_11() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_11 problem;
    problem.largest_product("../data/largest_product_in_a_grid.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_12() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_12 problem;
    problem.max_divisible_triangular_number();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_13() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_13 problem;
    problem.large_sum("../data/large_sum.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_14() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_14 problem;
    problem.collatz_sequence();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_15() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_15 problem;
    problem.lattice_paths();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_16() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_16 problem;
    problem.sum();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_17() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_17 problem;
    problem.letter_count();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_18() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_18 problem;
    problem.max_path();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_19() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_19 problem;
    problem.sundays();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_20() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_20 problem;
    problem.sum_of_factorial_digits(100);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_21() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_21 problem;
    problem.sum_of_amicable_numbers();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_22() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_22 problem;
    problem.names_scores("../data/names.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_23() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_23 problem;
    problem.non_abundant_sums();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_24() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_24 problem;
    problem.permutation_generator();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_25() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_25 problem;
    problem.fibonacci();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_26() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_26 problem;
    problem.reciprocal_cycles();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_27() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_27 problem;
    problem.quadratic_primes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_28() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_28 problem;
    problem.diagnols_sum();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_29() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_29 problem;
    problem.distinct_powers();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_30() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_30 problem;
    problem.digit_fifth_power();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_31() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_31 problem;
    problem.coin_sums();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_32() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_32 problem;
    problem.pandigital_product();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_33() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_33 problem;
    problem.digit_cancelling_fractions();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_34() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_34 problem;
    problem.digit_factorials();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_35() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_35 problem;
    problem.circular_primes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_36() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_36 problem;
    problem.double_base_palindromes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_37() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_37 problem;
    problem.truncatable_primes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_38() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_38 problem;
    problem.pandigital_multiples();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_39() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_39 problem;
    problem.integer_right_triangles();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_40() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_40 problem;
    problem.champernowne_constant();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_41() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_41 problem;
    problem.pandigital_prime();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_42() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_42 problem;
    problem.count_coded_triangle_numbers("../data/words.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_43() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_43 problem;
    problem.sub_string_divisiblity();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_44() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_44 problem;
    problem.min_difference();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_45() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_45 problem;
    problem.next_number();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_46() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_46 problem;
    problem.goldbach_conjecture();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_47() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_47 problem;
    problem.distinct_prime_factors();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_48() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_48 problem;
    problem.self_powers();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_49() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_49 problem;
    problem.prime_permutations();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_50() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_50 problem;
    problem.consecutive_prime_sum();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_52() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_52 problem;
    problem.permutated_multiples();

    m_end_timer();
}


void pt::TestSuite::m_test_case_for_problem_53() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_53 problem;
    problem.combinatronic_selection();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_54() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_54 problem;
    problem.count_player_wins(1);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_55() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_55 problem;
    problem.lychrel_numbers(10000);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_56() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_56 problem;
    problem.powerful_digit_sum();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_57() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_57 problem;
    problem.square_root_convergents();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_58() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_58 problem;
    problem.spiral_primes();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_59() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_59 problem;
    problem.sum_of_encrypted_message("../data/cipher.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_60() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_60 problem;
    problem.prime_pair_sets();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_63() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_63 problem;
    problem.powerful_digit_counts();
    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_64() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_64 problem;
    problem.count_continued_fractions_periods(10000);
    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_65() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_65 problem;
    problem.convergents_of_e();
    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_67() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_67 problem;
    problem.max_path();
    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_69() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_69 problem;
    const int n = 1000000;
    problem.totient_maximum(n);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_70() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_70 problem;
    problem.totient_permutation();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_71() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_71 problem;
    problem.ordered_fractions();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_72() {
    m_start_timer();
    const int n = 1000000;

    m_test_case_banner();
    pp::Problem_72 problem;
    printf("Counting fractions based on Euler's totient function for [%d] == [%ld]\n", n, problem.counting_fractions(n));

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_73() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_73 problem;
    problem.counting_fractions();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_74() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_74 problem;
    problem.digit_factorial_chains();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_76() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_76 problem;
    problem.count_sum(100);

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_80() {
    m_start_timer();
    m_test_case_banner();

    pp::Problem_80 problem;
    problem.square_root_digital_expansion();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_89() {
    m_start_timer();
    m_test_case_banner();

    pp::Problem_89 problem;
    problem.roman_numbers();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_92() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_92 problem;
    problem.square_digit_chains();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_97() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_97 problem;
    problem.large_prime();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_99() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_99 problem;
    problem.largest_number("../data/base_exp.txt");

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_125() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_125 problem;
    problem.palindromic_sums();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_145() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_145 problem;
    problem.count_reversables();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_187() {
    m_start_timer();
    const long n = 100000000;

    m_test_case_banner();
    pp::Problem_187 problem;
    printf("Total semi prime numbers below [%ld] == [%d]\n", n, problem.semi_primes(n));

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_206() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_206 problem;
    problem.concealed_square();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_214() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_214 problem;
    problem.totient_chains();

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_297() {
    m_start_timer();

    m_test_case_banner();
    pp::Problem_297 problem;
    problem.zeckendorf();

    m_end_timer();
}

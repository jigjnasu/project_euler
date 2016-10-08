#include "Problem_1.h"
#include "Problem_2.h"
#include <cstdio>
#include <ctime>

namespace pp = project_euler::problems;

void test_case_for_problem_1() {
    const std::clock_t start = clock();
    
    pp::Problem_1 problem;
    const int N = 999;
    printf("Sum == [%d]\n", (problem.Sum(3, N) + problem.Sum(5, N)) - problem.Sum(15, N));

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}

void test_case_for_problem_2() {
    const std::clock_t start = clock();
    
    pp::Problem_2 problem;
    printf("Sum of even fibbonacci numbers == [%d]\n", problem.Sum());

    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");        
}

int main() {
    printf("------------------------------------- Problem 1 ----------------------------------------\n");
    test_case_for_problem_1();
    printf("------------------------------------- Problem 2 ----------------------------------------\n");    
    test_case_for_problem_2();
    
    return 0;
}

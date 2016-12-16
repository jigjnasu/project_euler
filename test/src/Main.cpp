#include "TestSuite.h"

void run_a_test_case(int test_case) {
    project_euler::test::TestSuite suite;
    suite.run(test_case);
}

void run_all_test_cases() {
    project_euler::test::TestSuite suite;
    suite.run_all();
}

int main() {
    const int test_case = 57;
    run_a_test_case(test_case);
    
    //run_all_test_cases();
    
    return 0;
}

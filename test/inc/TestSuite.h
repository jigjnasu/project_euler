#ifndef PROJECT_EULER_TEST_TESTSUITE_H_
#define PROJECT_EULER_TEST_TESTSUITE_H_

#include <map>
#include <ctime>

namespace project_euler {
    namespace test {
        class TestSuite {
        public:
            TestSuite();
            ~TestSuite();

            void run(int test_case);
            void run_all();

            typedef void (TestSuite::*ptrFunc)();
        private:
            std::map<int, ptrFunc> m_test_cases_dictionary;

            void m_initialize_test_cases_dictionary();
            void m_execute(ptrFunc function);

            void m_start_timer();
            void m_end_timer() const;

            void m_test_case_banner(int test_case) const;

            void m_test_case_for_problem_1();
            void m_test_case_for_problem_2();

            std::clock_t m_start_time;
        };
    };
};

#endif // PROJECT_EULER_TEST_TESTSUITE_H_

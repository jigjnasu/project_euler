/*
  Test suite for all the Project Euler problems.
  Can run single test case by providing the problem number.
  Can run all the test cases one by one in ascending order.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 17th, 2016
 */

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
            std::clock_t m_start_time;
            int m_test_case;
            std::map<int, ptrFunc> m_test_cases_dictionary;

            void m_initialize_test_cases_dictionary();
            void m_execute(ptrFunc function);

            void m_start_timer();
            void m_end_timer() const;

            void m_test_case_banner() const;

            void m_test_case_for_problem_1();
            void m_test_case_for_problem_2();
            void m_test_case_for_problem_3();
            void m_test_case_for_problem_4();
            void m_test_case_for_problem_5();
            void m_test_case_for_problem_6();
            void m_test_case_for_problem_7();
            void m_test_case_for_problem_8();
            void m_test_case_for_problem_9();
            void m_test_case_for_problem_10();
            void m_test_case_for_problem_11();
            void m_test_case_for_problem_12();
            void m_test_case_for_problem_13();
            void m_test_case_for_problem_14();
            void m_test_case_for_problem_15();
            void m_test_case_for_problem_16();
            void m_test_case_for_problem_17();
            void m_test_case_for_problem_19();
            void m_test_case_for_problem_20();
            void m_test_case_for_problem_21();
            void m_test_case_for_problem_22();
            void m_test_case_for_problem_23();
            void m_test_case_for_problem_24();
            void m_test_case_for_problem_25();
            void m_test_case_for_problem_26();
            void m_test_case_for_problem_27();
            void m_test_case_for_problem_28();            
            void m_test_case_for_problem_29();
            void m_test_case_for_problem_30();
            void m_test_case_for_problem_31();
            void m_test_case_for_problem_32();
            void m_test_case_for_problem_33();
            void m_test_case_for_problem_34();
            void m_test_case_for_problem_35();
            void m_test_case_for_problem_36();
            void m_test_case_for_problem_37();
            void m_test_case_for_problem_38();
            void m_test_case_for_problem_39();
            void m_test_case_for_problem_40();
            void m_test_case_for_problem_41();
            void m_test_case_for_problem_42();
            void m_test_case_for_problem_43();
            void m_test_case_for_problem_44();
            void m_test_case_for_problem_45();
            void m_test_case_for_problem_46();
            void m_test_case_for_problem_47();
            void m_test_case_for_problem_48();
            void m_test_case_for_problem_49();
            void m_test_case_for_problem_50();
            void m_test_case_for_problem_52();
            void m_test_case_for_problem_53();            
            void m_test_case_for_problem_54();
            void m_test_case_for_problem_55();
            void m_test_case_for_problem_56();
            void m_test_case_for_problem_57();
            void m_test_case_for_problem_59();
            void m_test_case_for_problem_63();            
            void m_test_case_for_problem_64();
            void m_test_case_for_problem_65();            
            void m_test_case_for_problem_69();
            void m_test_case_for_problem_70();
            void m_test_case_for_problem_71();            
            void m_test_case_for_problem_72();
            void m_test_case_for_problem_73();
            void m_test_case_for_problem_74();
            void m_test_case_for_problem_76();
            void m_test_case_for_problem_80();
            void m_test_case_for_problem_92();
            void m_test_case_for_problem_97();
            void m_test_case_for_problem_99();
            void m_test_case_for_problem_125();
            void m_test_case_for_problem_187();
            void m_test_case_for_problem_214();
            void m_test_case_for_problem_297();
        };
    };
};

#endif // PROJECT_EULER_TEST_TESTSUITE_H_

#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <dbg.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_tested(test, message) do { printf("\e[31m\n%-10s : %s\e[0m",test, message); } while(0)
#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }
#define mu_run_test(test) do { message = test(); tests_run++; if (message) { debug("\n-----%s", " " #test);\
    tests_failed++; mu_tested(#test, message); } else { tests_passed++; } } while(0)

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    argc = 1;\
    printf("----\nRUNNING: %s\n\e[0m", argv[0]);\
    name();\
    if (!(tests_failed)) {\
        printf("\n\n\e[32mALL TESTS PASSED\n\e[0m");\
    }\
    printf("\n\n\e[33mTests run: %d\e[0m", tests_run);\
    printf("\n\e[32mTests passed: %d\e[0m", tests_passed);\
    printf("\n\e[31mTests failed: %d\n\n\e[0m", tests_failed);\
    exit(tests_failed);\
}


int tests_run;
int tests_failed;
int tests_passed;

#endif
#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <dbg.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_tested(test, message) do { printf("\n%-10s : %s",test, message); } while(0)
#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }
#define mu_run_test(test) do { message = test(); tests_run++; if (message) { debug("\n-----%s", " " #test);\
    tests_failed++; mu_tested(#test, message); } else { tests_passed++; } } while(0)

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    argc = 1;\
    printf("----\nRUNNING: %s\n", argv[0]);\
    name();\
    if (!(tests_failed)) {\
        printf("\n\nALL TESTS PASSED\n");\
    }\
    printf("\n\nTests run: %d", tests_run);\
    printf("\nTests passed: %d", tests_passed);\
    printf("\nTests failed: %d\n\n", tests_failed);\
    exit(tests_failed);\
}


int tests_run;
int tests_failed;
int tests_passed;

#endif
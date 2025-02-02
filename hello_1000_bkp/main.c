#include <stdio.h>

#ifndef _FLAG_RUNNING_TEST_
    #define GET_INPUT_DATA scanf
    #define PUT_OUTPUT_DATA printf
#else
    extern int get_input_data_tst(const char *__restrict, ...);
    extern int put_output_data_tst(const char *__restrict, ...);
    #define GET_INPUT_DATA get_input_data_tst
    #define PUT_OUTPUT_DATA put_output_data_tst
#endif

void run_challenge_hello_1000_bkp(void) {
    PUT_OUTPUT_DATA("Hello, World! -- anoter challenge!\n");
}

#ifndef _FLAG_RUNNING_TEST_
int main() {
    run_challenge_hello_1000_bkp();
    return 0;
}
#endif

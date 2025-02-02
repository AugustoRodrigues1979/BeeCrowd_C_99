#include <CUnit/Basic.h>
#include <stdio.h>
#include "datatst.h"

/* Enable flag for advice what we running tests... */
#define _FLAG_RUNNING_TEST_

/* Include source of challenge here */
#include "./../hello_1000_bkp/main.c"

/* Define AKA for call run_challenge */
#define RUN_CHALLENGE run_challenge_hello_1000_bkp

static void test_challenge_1_hello_1000() {
    RUN_CHALLENGE();
    CU_ASSERT_EQUAL(2, 2); //Dummy Test
}

int setup_test_hello_1000_bkp(void) {
    printf("\ncall %s from %s\n", __func__, __FILE__);
    return 0;
}

int tear_down_test_hello_1000_bkp(void) {
    printf("\ncall %s from %s\n", __func__, __FILE__);
    return 0;
}

ITEM_SUIT_TEST* setup_suit_test_hello_1000_bkp(int *amount_test, char *s_name_suit, int amount_char_suit_name) {
    int amount_char_writted = 0;
    static ITEM_SUIT_TEST suit_test;
    static ITEM_TEST_FUNCTION cb_lst_test[] = {
        { "test_challenge_1_hello_1000_bkp", test_challenge_1_hello_1000 },
        { "test_challenge_1_hello_1000_bkp_dup", test_challenge_1_hello_1000 },
    };
    *amount_test = sizeof(cb_lst_test) / sizeof(ITEM_TEST_FUNCTION);
    amount_char_writted = snprintf(s_name_suit, amount_char_suit_name - 1, "Suit Test Hello_1000");
    s_name_suit[amount_char_writted] = 0;


    suit_test.cb_lot_of_test = cb_lst_test;
    suit_test.cb_setup_test = (SETUP_TEST_FUNCTION)setup_test_hello_1000_bkp;
    suit_test.cb_tear_down_test = tear_down_test_hello_1000_bkp;

    return &suit_test;
}

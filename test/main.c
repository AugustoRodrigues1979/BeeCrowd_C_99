#include <CUnit/Basic.h>
#include "datatst.h"

/* Attention: Run makefile for create bellow header file */
#include "build/suittest.h"

#define SIZE_SUIT_NAME  30

int main() {
    int idx_suit_test = 0;
    int idx_test = 0;
    int amount_test = 0;
    char sSuitName[SIZE_SUIT_NAME+1] = { 0 };
    SETUP_TEST_FUNCTION setup_each_test_in_suit_test;
    TEAR_DOWN_TEST_FUNCTION tear_down_for_each_test_in_suit_test;
    ITEM_SUIT_TEST *group_suit_test;
    TEST_FUNCTION cb_test_function;
    char *s_name_test = NULL;

    CU_pSuite pSuite = 0;
    CU_initialize_registry();   

    while( all_suits_test[idx_suit_test] ) {
        group_suit_test = (*all_suits_test[idx_suit_test])(&amount_test,sSuitName,SIZE_SUIT_NAME);
        setup_each_test_in_suit_test = group_suit_test->cb_setup_test;
        tear_down_for_each_test_in_suit_test = group_suit_test->cb_tear_down_test;

        pSuite = CU_add_suite(sSuitName, setup_each_test_in_suit_test, tear_down_for_each_test_in_suit_test);
        if (NULL == pSuite) {
            CU_cleanup_registry();
            return CU_get_error();
        }

        for (idx_test = 0; idx_test < amount_test; idx_test++) {
            cb_test_function = group_suit_test->cb_lot_of_test[idx_test].cb_test;
            s_name_test = group_suit_test->cb_lot_of_test[idx_test].s_test_name;
            if( NULL == CU_add_test(pSuite, s_name_test, cb_test_function) ) {
                CU_cleanup_registry();
                return CU_get_error();
            }
        }
    
       idx_suit_test += 1;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}

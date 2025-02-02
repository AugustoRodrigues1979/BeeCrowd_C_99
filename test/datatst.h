#ifndef TEST_BASIC_STRUCT_H_SEEN
#define TEST_BASIC_STRUCT_H_SEEN

typedef int (*SETUP_TEST_FUNCTION)(void);
typedef int (*TEAR_DOWN_TEST_FUNCTION)(void);
typedef void (*TEST_FUNCTION)();

typedef struct _ITEM_TEST_FUNCTION {
    char *s_test_name;
    TEST_FUNCTION cb_test;
} ITEM_TEST_FUNCTION;

typedef struct _ITEM_SUIT_TEST_ {
    SETUP_TEST_FUNCTION cb_setup_test;
    TEAR_DOWN_TEST_FUNCTION cb_tear_down_test;
    ITEM_TEST_FUNCTION *cb_lot_of_test;
} ITEM_SUIT_TEST;

typedef ITEM_SUIT_TEST* (*GET_AMOUNT_TEST)(int *amount_test, char *s_name_suit, int amount_char_suit_name);

typedef GET_AMOUNT_TEST SUIT_TEST;

#endif

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "void_pointer_functions.h"
#include "exit_codes.h"

struct array_list
{
    void **elements;
    size_t current_size;
    size_t total_capacity;
};

// CREATE LIST TESTS
//***********************************************************************************************
// ensure a new array list is created
START_TEST(test_array_list_create)
{
    array_list_t *list = array_list_create(NULL, NULL);
    ck_assert_ptr_ne(list, NULL);

    array_list_destroy(&list);
}
END_TEST

// TEST LIST
static TFun array_list_create_tests[] =
{
    test_array_list_create,
    NULL
};

// INSERT TESTS
//***********************************************************************************************
START_TEST(test_array_list_insert_NULL_list)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    exit_code = array_list_insert(NULL, 0, &num_1);
    ck_assert_int_eq(exit_code, E_LIST_ERROR);
}
END_TEST

START_TEST(test_array_list_insert_NULL_data)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, NULL);
    ck_assert_int_eq(exit_code, E_NULL_POINTER);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_insert_int_single)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[0]), 10);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_insert_int_multi)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_array[] = {13, 52, 36, 41, 76, 85};

    array_list_t *list = array_list_create(NULL, NULL);

    //************************************
    // Insert elements
    //************************************

    // Ensure 13 at index 0
    exit_code = array_list_insert(list, 0, &num_array[0]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[0]), 13);

    // Ensure 52 at index 1
    exit_code = array_list_insert(list, 1, &num_array[1]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[1]), 52);

    // Ensure 36 at index 2
    exit_code = array_list_insert(list, 2, &num_array[2]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[2]), 36);

    // Ensure 41 at index 3
    exit_code = array_list_insert(list, 3, &num_array[3]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[3]), 41);

    // Ensure 76 at index 4
    exit_code = array_list_insert(list, 3, &num_array[4]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[4]), 76);

    //************************************
    // Verify capacity
    //************************************

    // Ensure that capacity is at 5
    ck_assert_int_eq(list->total_capacity, 5);

    //************************************
    // Insert additional element
    //************************************

    // Ensure 85 at index 5
    exit_code = array_list_insert(list, 5, &num_array[5]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(*((int *)list->elements[5]), 85);

    //************************************
    // Verify capacity again
    //************************************

    // Ensure that capacity has doubled by this point
    ck_assert_int_eq(list->total_capacity, 10);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_insert_string_single)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    const char *str = "hello";

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &str);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[0]), str), 0);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_insert_string_multi)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    const char *words[] = {"hello", "world", "I", "am", "big", "chungus"};

    array_list_t *list = array_list_create(NULL, NULL);

    //************************************
    // Insert elements
    //************************************

    // Ensure "hello" at index 0
    exit_code = array_list_insert(list, 0, &words[0]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[0]), words[0]), 0);

    // Ensure "world" at index 1
    exit_code = array_list_insert(list, 1, &words[1]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[1]), words[1]), 0);

    // Ensure "I" at index 2
    exit_code = array_list_insert(list, 2, &words[2]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[2]), words[2]), 0);

    // Ensure "am" at index 3
    exit_code = array_list_insert(list, 3, &words[3]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[3]), words[3]), 0);

    // Ensure "big" at index 4
    exit_code = array_list_insert(list, 4, &words[4]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[4]), words[4]), 0);

    //************************************
    // Verify capacity
    //************************************

    // Ensure that capacity is at 5
    ck_assert_int_eq(list->total_capacity, 5);

    //************************************
    // Insert additional element
    //************************************

    // Ensure "chungus" at index 5
    exit_code = array_list_insert(list, 5, &words[5]);
    ck_assert_int_eq(exit_code, E_SUCCESS);
    ck_assert_int_eq(strcmp(*((char **)list->elements[5]), words[5]), 0);

    //************************************
    // Verify capacity again
    //************************************

    // Ensure that capacity has doubled by this point
    ck_assert_int_eq(list->total_capacity, 10);

    array_list_destroy(&list);
}
END_TEST

// TEST LIST
static TFun array_list_insert_tests[] =
{
    test_array_list_insert_NULL_list,
    test_array_list_insert_NULL_data,
    test_array_list_insert_int_single,
    test_array_list_insert_int_multi,
    test_array_list_insert_string_single,
    test_array_list_insert_string_multi,
    NULL
};

// GET ELEMENT TESTS
//***********************************************************************************************
START_TEST(test_array_list_get_NULL_list)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    void *data_1 = array_list_get(NULL, 0);
    ck_assert_ptr_eq(data_1, NULL);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_get_int)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    void *data_1 = array_list_get(list, 0);
    ck_assert_int_eq(*((int *)data_1), 10);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_get_string)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    const char *str = "hello";

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &str);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    void *data_1 = array_list_get(list, 0);
    ck_assert_int_eq(strcmp(*((char **)data_1), str), 0);

    array_list_destroy(&list);
}
END_TEST

// TEST LIST
static TFun array_list_get_tests[] =
{
    test_array_list_get_NULL_list,
    test_array_list_get_int,
    test_array_list_get_string,
    NULL
};

// SET ELEMENT TESTS
//***********************************************************************************************
START_TEST(test_array_list_set_NULL_list)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    int num_2 = 76;

    exit_code = array_list_set(NULL, 0, &num_2);
    ck_assert_int_eq(exit_code, E_LIST_ERROR);
    ck_assert_int_eq(num_1, 10);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_set_NULL_data)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    exit_code = array_list_set(list, 0, NULL);
    ck_assert_int_eq(exit_code, E_NULL_POINTER);
    ck_assert_int_eq(num_1, 10);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_set_int)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    int num_1 = 10;

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &num_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    // Ensure the first index now points to 'num_1'
    ck_assert_int_eq(*((int *)list->elements[0]), 10);

    int num_2 = 76;

    exit_code = array_list_set(list, 0, &num_2);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    // Ensure the first index now points to 'num_2'
    ck_assert_int_eq(*((int *)list->elements[0]), 76);

    array_list_destroy(&list);
}
END_TEST

START_TEST(test_array_list_set_string)
{
    exit_code_t exit_code = E_DEFAULT_ERROR;

    const char *str_1 = "hello";

    array_list_t *list = array_list_create(NULL, NULL);
    exit_code = array_list_insert(list, 0, &str_1);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    // Ensure the first index points to 'str_1'
    ck_assert_int_eq(strcmp(*((char **)list->elements[0]), str_1), 0);

    const char *str_2 = "world";

    exit_code = array_list_set(list, 0, &str_2);
    ck_assert_int_eq(exit_code, E_SUCCESS);

    // Ensure the first index now points to 'str_2'
    ck_assert_int_eq(strcmp(*((char **)list->elements[0]), str_2), 0);

    array_list_destroy(&list);
}
END_TEST

// TEST LIST
static TFun array_list_set_tests[] =
{
    test_array_list_set_NULL_list,
    test_array_list_set_NULL_data,
    test_array_list_set_int,
    test_array_list_set_string,
    NULL
};

static void add_tests(TCase * test_cases, TFun * test_functions)
{
    while (* test_functions)
    {
        // add the test from the core_tests array to the tcase
        tcase_add_test(test_cases, * test_functions);
        test_functions++;
    }
}

Suite *array_list_test_suite(void)
{
    Suite *array_list_test_suite = suite_create("Array List Tests");

    // Create array_list_create tests
    TFun *array_list_create_test_list = array_list_create_tests;
    TCase *array_list_create_test_cases = tcase_create(" array_list_create() Tests");
    add_tests(array_list_create_test_cases, array_list_create_test_list);
    suite_add_tcase(array_list_test_suite, array_list_create_test_cases);

    // Create array_list_insert tests
    TFun *array_list_insert_test_list = array_list_insert_tests;
    TCase *array_list_insert_test_cases = tcase_create(" array_list_insert() Tests");
    add_tests(array_list_insert_test_cases, array_list_insert_test_list);
    suite_add_tcase(array_list_test_suite, array_list_insert_test_cases);

    // Create array_list_get tests
    TFun *array_list_get_test_list = array_list_get_tests;
    TCase *array_list_get_test_cases = tcase_create(" array_list_get() Tests");
    add_tests(array_list_get_test_cases, array_list_get_test_list);
    suite_add_tcase(array_list_test_suite, array_list_get_test_cases);

    // Create array_list_set tests
    TFun *array_list_set_test_list = array_list_set_tests;
    TCase *array_list_set_test_cases = tcase_create(" array_list_set() Tests");
    add_tests(array_list_set_test_cases, array_list_set_test_list);
    suite_add_tcase(array_list_test_suite, array_list_set_test_cases);

    return array_list_test_suite;
}

#include "array_list.h"
#include "utilities.h"

static int array_list_insert(array_list_t * list, uint32_t index, void * data);

array_list_t * array_list_new(FREE_F   free_func,
                              CMP_F    comp_func,
                              uint32_t initial_capacity)
{
    array_list_t * new_list = NULL;

    if ((NULL == free_func) || (NULL == comp_func))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    // Create the array list
    new_list = calloc(1, sizeof(array_list_t));
    if (NULL == new_list)
    {
        print_error("CMR failure.");
        goto END;
    }

    // Allocate space for each element
    new_list->data = calloc(initial_capacity, sizeof(void *));
    if (NULL == new_list->data)
    {
        free(new_list);
        new_list = NULL;
        goto END;
    }

    new_list->capacity     = initial_capacity;
    new_list->size         = 0;
    new_list->custom_free  = free_func;
    new_list->compare_func = comp_func;

END:
    return new_list;
}

int array_list_push_head(array_list_t * list, void * data)
{
    int exit_code = E_FAILURE;

    if ((NULL == list) || (NULL == data))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_push_tail(array_list_t * list, void * data)
{
    int exit_code = E_FAILURE;

    if ((NULL == list) || (NULL == data))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_push_position(array_list_t * list,
                             void *         data,
                             uint32_t       position)
{
    int exit_code = E_FAILURE;

    if ((NULL == list) || (NULL == data))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if ((0 > position) || position > list->size)
    {
        print_error("Position out of bounds.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_empty_check(array_list_t * list)
{
    int exit_code = E_FAILURE;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

void * array_list_pop_head(array_list_t * list)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

END:
    return element;
}

void * array_list_pop_tail(array_list_t * list)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

END:
    return element;
}

void * array_list_pop_position(array_list_t * list, uint32_t position)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if ((0 > position) || position > list->size)
    {
        print_error("Position out of bounds.");
        goto END;
    }

END:
    return element;
}

int array_list_remove_head(array_list_t * list)
{
    int exit_code = E_FAILURE;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_remove_tail(array_list_t * list)
{
    int exit_code = E_FAILURE;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_remove_position(array_list_t * list, uint32_t position)
{
    int exit_code = E_FAILURE;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if ((0 > position) || position > list->size)
    {
        print_error("Position out of bounds.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

void * array_list_peek_head(array_list_t * list)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

END:
    return element;
}

void * array_list_peek_tail(array_list_t * list)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

END:
    return element;
}

void * array_list_peek_position(array_list_t * list, uint32_t position)
{
    void * element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if ((0 > position) || position > list->size)
    {
        print_error("Position out of bounds.");
        goto END;
    }

END:
    return element;
}

int array_list_remove_data(array_list_t * list, void ** item_to_remove)
{
    int    exit_code         = E_FAILURE;
    void * element_to_remove = NULL;

    if (NULL == list || NULL == item_to_remove || NULL == *item_to_remove)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_foreach_call(array_list_t * list, ACT_F action_function)
{
    int    exit_code       = E_FAILURE;
    void * current_element = NULL;

    if ((NULL == list) || (NULL == action_function))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

void * array_list_find_first_occurrence(array_list_t * list,
                                        void **        search_data)
{
    void * current_element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    current_element = NULL; // Set back to NULL if no match was found
END:
    return current_element;
}

array_list_t * array_list_find_all_occurrences(array_list_t * list,
                                               void **        search_data)
{
    array_list_t * new_list        = NULL;
    void *         current_element = NULL;
    int            check           = E_FAILURE;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if (0 == list->size)
    {
        print_error("Empty list.");
        goto END;
    }

END:
    return new_list;
}

int array_list_sort(array_list_t * list)
{
    int exit_code = E_FAILURE;

    if (NULL != list)
    {
        // code here
    }

    return exit_code;
}

int array_list_clear(array_list_t * list)
{
    int    exit_code       = E_FAILURE;
    void * current_element = NULL;

    if (NULL == list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int array_list_delete(array_list_t ** list)
{
    int exit_code = E_FAILURE;

    if (NULL == *list)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    exit_code = E_SUCCESS;
END:
    return exit_code;
}
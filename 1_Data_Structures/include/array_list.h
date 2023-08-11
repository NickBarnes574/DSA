#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "comparisons.h"

/**
 * @brief A pointer to a user-defined function that gets called in the
 * foreach_call on each item in the array list.
 */
typedef void (*ACT_F)(void *);

/**
 * @brief A pointer to a user-defined free function. This is used to free
 * memory allocated for list data. For simple data types, this is just a
 * pointer to the standard free function. More complex structs stored in array
 * lists may require a function that calls free on multiple components.
 */
typedef void (*FREE_F)(void *);

typedef struct array_list
{
    void **  data;
    uint32_t size;
    uint32_t capacity;
    FREE_F   custom_free;
    CMP_F    compare_func;
} array_list_t;

/**
 * @brief creates a new array list
 *
 * @param customfree pointer to the free function to be used with that array
 * list.
 * @param compare_function pointer to the compare function to be used with
 * that list.
 * @param initial_capacity the capacity of the newly created array list
 * @returns pointer to allocated array list on success or NULL on failure
 */
array_list_t * array_list_new(FREE_F, CMP_F, uint32_t initial_capacity);

/**
 * @brief pushes a new node onto the head of an array list
 *
 * @param list array list to push the node into
 * @param data data to be pushed into node
 * @returns 0 on success, non-zero value on failure
 */
int array_list_push_head(array_list_t * list, void * data);

/**
 * @brief pushes a new node onto the tail of an array list
 *
 * @param list array list to push the node into
 * @param data data to be pushed into node
 * @return 0 on success, non-zero value on failure
 */
int array_list_push_tail(array_list_t * list, void * data);

/**
 * @brief pushes a new node onto an array list at a specific position
 *
 * @param list array list to push the node into
 * @param data data to be pushed into node
 * @param position the position in which to insert the node
 * @return 0 on success, non-zero value on failure
 */
int array_list_push_position(array_list_t * list,
                             void *         data,
                             uint32_t       position);

/**
 * @brief checks if the array list object is empty
 *
 * @param list pointer to array list object to be checked
 * @returns non-zero if list is empty, 0 value if not empty
 */
int array_list_empty_check(array_list_t * list);

/**
 * @brief pops the head node out of the array list
 *
 * @param list list to pop the node out of
 * @return pointer to popped node on success, NULL on failure
 */
void * array_list_pop_head(array_list_t * list);

/**
 * @brief pops the tail node out of the array list
 *
 * @param list list to pop the node out of
 * @return pointer to popped node on success, NULL on failure
 */
void * array_list_pop_tail(array_list_t * list);

/**
 * @brief pops a node out of an array list at a specific position
 *
 * @param list array list to pop the node out of
 * @param position position of the node
 * @return pointer to popped node on success, NULL on failure
 */
void * array_list_pop_position(array_list_t * list, uint32_t position);

/**
 * @brief removes a node from the head of an array list
 *
 * @param list array list to remove the node from
 * @return non-zero if list is empty, 0 value if not empty
 */
int array_list_remove_head(array_list_t * list);

/**
 * @brief removes a node from the tail of an array list
 *
 * @param list array list to remove the node from
 * @return non-zero if list is empty, 0 value if not empty
 */
int array_list_remove_tail(array_list_t * list);

/**
 * @brief removes a node from an array list at a specific position
 *
 * @param list array list to remove the node from
 * @param position position of the node
 * @return non-zero if list is empty, 0 value if not empty
 */
int array_list_remove_position(array_list_t * list, uint32_t position);

/**
 * @brief get the data from the node at the head of an array list without
 *        popping
 *
 * @param list array list to pop the node out of
 * @return pointer to head node on success, NULL on failure
 */
void * array_list_peek_head(array_list_t * list);

/**
 * @brief get the data from the node at the tail of an array list without
 *        popping
 *
 * @param list array list to pop the node out of
 * @return pointer to tail node on success, NULL on failure
 */
void * array_list_peek_tail(array_list_t * list);

/**
 * @brief get the data from the node at a specific position of an array list
 * without popping
 *
 * @param list array list to pop the node out of
 * @param position position of the node
 * @return pointer to tail node on success, NULL on failure
 */
void * array_list_peek_position(array_list_t * list, uint32_t position);

/**
 * @brief remove a specific node from an array list based on the data stored
 *        in that node
 *
 * @param list array list to remove the node from
 * @param item_to_remove the data object to be searched for
 * @return 0 on success, non-zero value on failure
 */
int array_list_remove_data(array_list_t * list, void ** item_to_remove);

/**
 * @brief perform a user defined action on the data contained in all of the
 *        nodes in an array list
 *
 * @param list array list to perform actions on
 * @param action_function pointer to user defined action function
 * @return 0 on success, non-zero value on failure
 */
int array_list_foreach_call(array_list_t * list, ACT_F action_function);

/**
 * @brief find the first occurrence of a node containing the search_data as
 *        found by the user defined compare function
 *
 * @param list array list to search through
 * @param search_data is the pointer to the address of the data to be searched
 *                    for
 * @return pointer to node found on success, NULL on failure
 */
void * array_list_find_first_occurrence(array_list_t * list,
                                        void **        search_data);

/**
 * @brief find all occurrences of a node containing the search_data as
 *        found by the user defined compare function
 *
 * @param list array list to search through
 * @param receiving_list pointer to receiving list
 * @param search_data is the pointer to the address of the data to be searched
 *                    for
 * @return pointer to list of all found occurrecnces on success, NULL on failure
 */
array_list_t * array_list_find_all_occurrences(array_list_t * list,
                                               void **        search_data);

/**
 * @brief sort array list as per user defined compare function
 *
 * @param list pointer to array list to be sorted
 * @return 0 on success, non-zero value on failure
 */
int array_list_sort(array_list_t * list);

/**
 * @brief clear all nodes out of an array list
 *
 * @param list array list to clear out
 * @return 0 on success, non-zero value on failure
 */
int array_list_clear(array_list_t * list);

/**
 * @brief delete an array list
 *
 * @param list_address pointer to list pointer
 * @return 0 on success, non-zero value on failure
 */
int array_list_delete(array_list_t ** list);

#endif

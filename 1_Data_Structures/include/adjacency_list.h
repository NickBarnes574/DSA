#ifndef _ADJACENCY_LIST_H
#define _ADJACENCY_LIST_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "comparisons.h"
#include "linked_list.h"

#define MAX_LABEL_SIZE 1024

/**
 * @brief A pointer to a user-defined free function.
 *
 * This typedef defines a function pointer type that represents a custom free
 * function. It's used to free memory allocated for specific data types.
 * For simple data types, this may be a pointer to the standard free function.
 * More complex types may require a custom function that calls free on multiple
 * components.
 *
 * @param void* Pointer to the data to be freed.
 */
typedef void (*FREE_F)(void *);

/**
 * @brief A pointer to a user-defined print function.
 *
 * This typedef defines a function pointer type that represents a custom print
 * function. It's used to print the content of specific data types in a
 * human-readable format.
 *
 * @param void* Pointer to the data to be printed.
 */
typedef void (*PRINT_F)(void *);

/**
 * @brief Represents a vertex in the graph
 *
 */
typedef struct vertex
{
    char   label[MAX_LABEL_SIZE]; // Label for this vertex
    void * data;                  // Pointer to the data for this vertex
} vertex_t;

/**
 * @brief Represents an edge in the graph
 *
 */
typedef struct edge
{
    vertex_t * destination; // Pointer to the destination vertex
    int        weight;      // Weight of the edge
} edge_t;

/**
 * @brief Represents the entire graph itself
 *
 */
typedef struct graph
{
    int  num_vertices;      // Number of vertices in the graph
    bool is_directed;       // Flag to indicate if the graph is directed
    list_t **
            adjacency_list; // Array of pointers to adjacency lists (of edge_t)
    CMP_F   compare_func;   // Comparison function for vertices
    FREE_F  free_func;      // Free function for vertices
    PRINT_F print_func;     // Print function for vertices
} graph_t;

/***********************************************************************
 * INITIALIZATION
 ***********************************************************************/

/**
 * @brief Create a new graph.
 * @param is_directed Boolean flag to indicate if the graph is directed.
 * @param compare_func Comparison function for vertices.
 * @param free_func Free function for vertices.
 * @param print_func Print function for vertices.
 * @return Pointer to the newly created graph.
 */
graph_t * graph_create(bool    is_directed,
                       CMP_F   compare_func,
                       FREE_F  free_func,
                       PRINT_F print_func);

/**
 * @brief Add a vertex to the graph.
 * @param graph Pointer to the graph.
 * @param label Label for the new vertex.
 * @param data Pointer to the data for the new vertex.
 * @return Status code indicating success or failure.
 */
int graph_add_vertex(graph_t * graph, const char * label, void * data);

/**
 * @brief Add an edge to the graph.
 * @param graph Pointer to the graph.
 * @param label_source Label of the source vertex.
 * @param label_destination Label of the destination vertex.
 * @param weight Weight of the edge.
 * @return Status code indicating success or failure.
 */
int add_edge(graph_t *    graph,
             const char * label_source,
             const char * label_destination,
             int          weight);

/***********************************************************************
 * QUERY OPERATIONS
 ***********************************************************************/

/**
 * @brief Get neighbors of a vertex.
 * @param graph Pointer to the graph.
 * @param label_vertex Label of the vertex whose neighbors are to be retrieved.
 * @return List of neighbors.
 */
list_t * get_neighbors(graph_t * graph, const char * label_vertex);

/**
 * @brief Check if an edge exists between two vertices.
 * @param graph Pointer to the graph.
 * @param label_source Label of the source vertex.
 * @param label_destination Label of the destination vertex.
 * @return Boolean value indicating the presence of the edge.
 */
bool is_edge(graph_t *    graph,
             const char * label_source,
             const char * label_destination);

/**
 * @brief Get the number of vertices in the graph.
 * @param graph Pointer to the graph.
 * @return Number of vertices.
 */
int get_vertex_count(graph_t * graph);

/**
 * @brief Get the number of edges in the graph.
 * @param graph Pointer to the graph.
 * @return Number of edges.
 */
int get_edge_count(graph_t * graph);

/***********************************************************************
 * MODIFICATION OPERATIONS
 ***********************************************************************/

/**
 * @brief Remove an edge from the graph.
 * @param graph Pointer to the graph.
 * @param label_source Label of the source vertex.
 * @param label_destination Label of the destination vertex.
 * @return Status code indicating success or failure.
 */
int remove_edge(graph_t *    graph,
                const char * label_source,
                const char * label_destination);

/**
 * @brief Remove a vertex from the graph.
 * @param graph Pointer to the graph.
 * @param label_vertex Label of the vertex to be removed.
 * @return Status code indicating success or failure.
 */
int remove_vertex(graph_t * graph, const char * label_vertex);

/**
 * @brief Update the weight of an edge.
 * @param graph Pointer to the graph.
 * @param label_source Label of the source vertex.
 * @param label_destination Label of the destination vertex.
 * @param new_weight New weight for the edge.
 * @return Status code indicating success or failure.
 */
int update_edge_weight(graph_t *    graph,
                       const char * label_source,
                       const char * label_destination,
                       int          new_weight);

/**
 * @brief Clear all vertices and edges from the graph.
 * @param graph Pointer to the graph.
 * @return Status code indicating success or failure.
 */
int clear_graph(graph_t * graph);

/***********************************************************************
 * TRAVERSAL
 ***********************************************************************/

/**
 * @brief Perform a depth-first search starting from a given vertex.
 * @param graph Pointer to the graph.
 * @param label_start_vertex Label of the starting vertex.
 * @param action_function Function to call on each vertex during traversal.
 * @return Status code indicating success or failure.
 */
int depth_first_search(graph_t *    graph,
                       const char * label_start_vertex,
                       ACT_F        action_function);

/**
 * @brief Perform a breadth-first search starting from a given vertex.
 * @param graph Pointer to the graph.
 * @param label_start_vertex Label of the starting vertex.
 * @param action_function Function to call on each vertex during traversal.
 * @return Status code indicating success or failure.
 */
int breadth_first_search(graph_t *    graph,
                         const char * label_start_vertex,
                         ACT_F        action_function);

/***********************************************************************
 * MISCELLANEOUS
 ***********************************************************************/

/**
 * @brief Print the graph in a human-readable format.
 * @param graph Pointer to the graph.
 */
void print_graph(graph_t * graph);

/**
 * @brief Find the shortest path between two vertices using algorithms like
 * Dijkstra's or Bellman-Ford.
 * @param graph Pointer to the graph.
 * @param label_start_vertex Label of the starting vertex.
 * @param label_end_vertex Label of the ending vertex.
 * @return List representing the shortest path.
 */
list_t * find_shortest_path(graph_t *    graph,
                            const char * label_start_vertex,
                            const char * label_end_vertex);

/***********************************************************************
 * DESTRUCTION
 ***********************************************************************/

/**
 * @brief Free all memory associated with the graph, including the memory for
 * vertices, edges, and any additional data structures.
 * @param graph Address of the pointer to the graph.
 */
void graph_destroy(graph_t ** graph);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adjacency_list.h"
#include "utilities.h"

/**
 * @brief Find a vertex in the graph by its label.
 * @param graph Pointer to the graph where the search is performed.
 * @param label Label of the vertex to find.
 * @return Pointer to the vertex if found, NULL if not found.
 */
static vertex_t * find_vertex_by_label(graph_t * graph, const char * label);

/**
 * @brief Create a new vertex with the given label and data.
 * @param label Label for the new vertex.
 * @param data Pointer to the data for the new vertex.
 * @return Pointer to the newly created vertex.
 */
static vertex_t * create_vertex(const char * label, void * data);

/**
 * @brief Create a new edge with the given destination vertex and weight.
 * @param destination Pointer to the destination vertex.
 * @param weight Weight of the edge.
 * @return Pointer to the newly created edge.
 */
static edge_t * create_edge(vertex_t * destination, int weight);

/***********************************************************************
 * INITIALIZATION
 ***********************************************************************/

graph_t * graph_create(bool    is_directed,
                       CMP_F   compare_func,
                       FREE_F  free_func,
                       PRINT_F print_func)
{
    graph_t * graph = NULL;

    if ((NULL == compare_func) || (NULL == free_func))
    {
        print_error("Must provide a compare and free function.");
        goto END;
    }

    graph = calloc(1, sizeof(graph_t));
    if (NULL == graph)
    {
        print_error("CMR failure.");
        goto END;
    }

    graph->vertices     = NULL;
    graph->compare_func = compare_func;
    graph->free_func    = free_func;
    graph->is_directed  = is_directed;
    graph->num_vertices = 0;
    graph->print_func   = print_func;

END:
    return graph;
}

int graph_add_vertex(graph_t * graph, const char * label, void * data)
{
    int        exit_code = E_FAILURE;
    vertex_t * vertex    = NULL;

    if ((NULL == graph) || (NULL == label) || (NULL == data))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    vertex = create_vertex(label, data);
    if (NULL == vertex)
    {
        print_error("Unable to create vertex.");
        goto END;
    }

    // Check if adjacency list is NULL and create a new one if needed
    if (NULL == graph->vertices)
    {
        graph->vertices = list_new(graph->free_func, graph->compare_func);
        if (NULL == graph->vertices)
        {
            print_error("Unable to create adjacency list.");
            goto END;
        }
    }

    // Append the new vertex to the list
    exit_code = list_push_tail(graph->vertices, vertex);
    if (E_SUCCESS != exit_code)
    {
        print_error("Unable to add vertex to adjacency list.");
        goto END;
    }

    // Increment the number of vertices
    graph->num_vertices++;

    exit_code = E_SUCCESS;
END:
    return exit_code;
}

int add_edge(graph_t *    graph,
             const char * label_source,
             const char * label_destination,
             int          weight)
{
    return 0;
}

/***********************************************************************
 * QUERY OPERATIONS
 ***********************************************************************/

list_t * get_neighbors(graph_t * graph, const char * label_vertex)
{
    return NULL;
}

bool is_edge(graph_t *    graph,
             const char * label_source,
             const char * label_destination)
{
    return false;
}

int get_vertex_count(graph_t * graph)
{
    return 0;
}

int get_edge_count(graph_t * graph)
{
    return 0;
}

/***********************************************************************
 * MODIFICATION OPERATIONS
 ***********************************************************************/

int remove_edge(graph_t *    graph,
                const char * label_source,
                const char * label_destination)
{
    return 0;
}

int remove_vertex(graph_t * graph, const char * label_vertex)
{
    return 0;
}

int update_edge_weight(graph_t *    graph,
                       const char * label_source,
                       const char * label_destination,
                       int          new_weight)
{
    return 0;
}

int clear_graph(graph_t * graph)
{
    return 0;
}

/***********************************************************************
 * TRAVERSAL
 ***********************************************************************/

int depth_first_search(graph_t *    graph,
                       const char * label_start_vertex,
                       ACT_F        action_function)
{
    return 0;
}

int breadth_first_search(graph_t *    graph,
                         const char * label_start_vertex,
                         ACT_F        action_function)
{
    return 0;
}

/***********************************************************************
 * MISCELLANEOUS
 ***********************************************************************/

void print_graph(graph_t * graph)
{
    return;
}

list_t * find_shortest_path(graph_t *    graph,
                            const char * label_start_vertex,
                            const char * label_end_vertex)
{
    return NULL;
}

/***********************************************************************
 * DESTRUCTION
 ***********************************************************************/

void graph_destroy(graph_t ** graph)
{
    return;
}

/***********************************************************************
 * NOTE: STATIC FUNCTIONS LISTED BELOW
 ***********************************************************************/

static vertex_t * find_vertex_by_label(graph_t * graph, const char * label)
{
    return NULL;
}

static vertex_t * create_vertex(const char * label, void * data)
{
    vertex_t * vertex = NULL;

    if ((NULL == label) || (NULL == data))
    {
        print_error("NULL argument passed.");
        goto END;
    }

    if (MAX_LABEL_SIZE < strlen(label))
    {
        print_error("'label' contains too many characters.");
        goto END;
    }

    vertex = calloc(1, sizeof(vertex_t));
    if (NULL == vertex)
    {
        print_error("CMR failure.");
        goto END;
    }

    strncpy(vertex->label, label, MAX_LABEL_SIZE - 1); // Copy the label
    vertex->data  = data;
    vertex->edges = NULL;

END:
    return vertex;
}

static edge_t * create_edge(vertex_t * destination, int weight)
{
    return NULL;
}

/*** end of file ***/

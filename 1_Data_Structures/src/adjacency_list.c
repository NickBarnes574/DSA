#include "adjacency_list.h"

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
    return NULL;
}

int graph_add_vertex(graph_t * graph, const char * label, void * data)
{
    return 0;
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
    return NULL;
}

static edge_t * create_edge(vertex_t * destination, int weight)
{
    return NULL;
}

/*** end of file ***/

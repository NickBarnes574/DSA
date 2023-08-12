#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"

void print_error(const char * p_message)
{
    /* [ACTION]: Suppressing fprintf() error.
     * [JUSTIFICATION]: Result inconsequential to any further operations.
     */
    // NOLINTNEXTLINE
    fprintf(stderr, "[ERROR]: %s\n", p_message);
}

void print_errno(const char * p_message, char * p_errno)
{
    /* [ACTION]: Suppressing fprintf() error.
     * [JUSTIFICATION]: Result inconsequential to any further operations.
     */
    // NOLINTNEXTLINE
    fprintf(stderr, "[ERROR]: %s\n[errno]: %s\n", p_message, p_errno);
}

char * copy_string(const char * p_source)
{
    char * p_dest = NULL;
    int    length = 0;

    if (NULL == p_source)
    {
        print_error("NULL argument passed.");
        goto END;
    }

    length = strlen(p_source);
    p_dest = calloc(1, length + 1); // +1 for NULL terminator
    if (NULL != p_dest)
    {
        snprintf(p_dest, length + 1, "%s", p_source);
    }

END:
    return p_dest;
}

/*** end of file ***/

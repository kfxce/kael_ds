#include "kael_ds.h"
#include <stdlib.h>

struct LinkQueue *init_link_queue()
{
    struct LinkList *link_list = init_link_list();
    if (!link_list)
        return NULL;

    struct LinkQueue *link_queue = malloc(sizeof(struct LinkList));
    if (!link_queue)
    {
        free(link_list);
        link_list = NULL;
        return NULL;
    }
    link_queue -> link_list = link_list;
    return link_queue;
}


int en_link_queue(struct LinkQueue *link_queue, void *data)
{
    if (!link_queue || !data)
        return ERR;
    
    int success = insert_link_list(link_queue -> link_list, 0, data);
    return success;
}


void *de_link_queue(struct LinkQueue *link_queue)
{
    if (!link_queue)
        return NULL;

    struct LinkList *link_list = link_queue -> link_list;
    int pos = link_list -> m_size - 1;
    void *data = get_by_pos_link_list(link_list, pos);
    int result = remove_by_pos_link_list(link_list, pos);
    if (result != True)
        return NULL;
    return data;
}


int size_link_queue(struct LinkQueue *link_queue)
{
    if (!link_queue)
        return ERR;

    return link_queue -> link_list -> m_size;
}


int destroy_link_queue(struct LinkQueue *link_queue)
{
    if (!link_queue)
        return ERR;

    int ok = destroy_link_list(link_queue -> link_list);
    if (ok != True)
        return ok;
    free(link_queue);
    link_queue = NULL;
    return True;
}


int is_empty_link_queue(struct LinkQueue *link_queue)
{
    if (!link_queue)
        return ERR;

    return is_empty_link_list(link_queue -> link_list);
}

#include "kfxce_ds.h"
#include <stdlib.h>

struct LinkStack *init_link_stack()
{
    struct LinkStack *link_stack = 
        malloc(sizeof(struct LinkStack));
    if (!link_stack)
        return NULL;
    link_stack -> header.next = NULL;
    link_stack -> header.data = NULL;
    link_stack -> m_size = 0;
    return link_stack;
}

int push_link_stack(struct LinkStack *link_stack, void *data)
{
    if (!link_stack || !data)
        return ERR;

    struct LinkStackNode *new_link_stack_node = 
        malloc(sizeof(struct LinkStackNode));

    if (!new_link_stack_node)
        return ERR;

    struct LinkStackNode *first_link_stack_node = 
        &link_stack -> header;

    new_link_stack_node -> data = data;
    new_link_stack_node -> next = 
        first_link_stack_node -> next;
    first_link_stack_node -> next = new_link_stack_node;

    link_stack -> m_size ++;

    return True;
}

void *pop_link_stack(struct LinkStack *link_stack)
{
    if (!link_stack)
        return NULL;

    if (link_stack -> m_size == 0)
        return NULL;

    struct LinkStackNode *first_link_stack_node = 
        link_stack -> header.next;
    link_stack -> header.next = first_link_stack_node -> next;

    void *data = first_link_stack_node -> data;
    first_link_stack_node -> next = NULL;

    free(first_link_stack_node);
    first_link_stack_node = NULL;

    link_stack -> m_size --;

    return data;
}

void *top_link_stack(struct LinkStack *link_stack)
{
    if (!link_stack)
        return NULL;

    if (link_stack -> m_size == 0)
        return NULL;

    struct LinkStackNode *first_link_stack_node = link_stack -> header.next;
    void *data = first_link_stack_node -> data;

    return data;
}

int is_empty_link_stack(struct LinkStack *link_stack)
{
    if (!link_stack)
        return ERR;

    if (link_stack -> m_size == 0)
        return True;
    return False;
}

int size_link_stack(struct LinkStack *link_stack)
{
    if (!link_stack)
        return ERR;

    return link_stack -> m_size;
}

int destroy_link_stack(struct LinkStack *link_stack)
{
    if (!link_stack)
        return ERR;

    free(link_stack);    
    link_stack = NULL;

    return True;
}

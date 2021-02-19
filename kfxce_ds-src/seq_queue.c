#include "kfxce_ds.h"
#include <stdlib.h>

struct SeqQueue *init_seq_queue(int capacity)
{
    if (capacity > SEQ_QUEUE_MAX)
        return NULL;

    struct DynamicArray *dynamic_array = init_dynamic_array(capacity);
    if (!dynamic_array)
        return NULL;

    struct SeqQueue *seq_queue = malloc(sizeof(struct DynamicArray));
    if (!seq_queue)
    {
        free(dynamic_array);
        dynamic_array = NULL;
        return NULL;
    }
    seq_queue -> dynamic_array = dynamic_array;
    return seq_queue;
}


int en_seq_queue(struct SeqQueue *seq_queue, void *data)
{
    if (!seq_queue || !data)
        return ERR;
    
    if (seq_queue -> dynamic_array -> m_size > SEQ_QUEUE_MAX)
        return ERR;

    int success = insert_dynamic_array(seq_queue -> dynamic_array, 0, data);
    return success;
}


void *de_seq_queue(struct SeqQueue *seq_queue)
{
    if (!seq_queue)
        return NULL;

    struct DynamicArray *dynamic_array = seq_queue -> dynamic_array;
    int pos = dynamic_array -> m_size - 1;
    void *data = get_by_pos_dynamic_array(dynamic_array, pos);
    int result = remove_by_pos_dynamic_array(dynamic_array, pos);
    if (result != True)
        return NULL;
    return data;
}


int size_seq_queue(struct SeqQueue *seq_queue)
{
    if (!seq_queue)
        return ERR;

    return seq_queue -> dynamic_array -> m_size;
}


int destroy_seq_queue(struct SeqQueue *seq_queue)
{
    if (!seq_queue)
        return ERR;

    int ok = destroy_dynamic_array(seq_queue -> dynamic_array);
    if (ok != True)
        return ok;
    free(seq_queue);
    seq_queue = NULL;
    return True;
}


int is_empty_seq_queue(struct SeqQueue *seq_queue)
{
    if (!seq_queue)
        return ERR;

    return is_empty_dynamic_array(seq_queue -> dynamic_array);
}

#include <stdlib.h>
#include "kael_ds.h"
#include <string.h>

struct SeqStack *init_seq_stack()
{
    struct SeqStack *seq_stack = malloc(sizeof(struct SeqStack));
    if (!seq_stack)
        return NULL;

    // 清空数组中的每个元素
    memset(seq_stack -> data, 0, sizeof(void *) * STACK_MAX);
    seq_stack -> m_size = 0;

    return seq_stack;
}

int push_seq_stack(struct SeqStack *seq_stack, void *data)
{
    if (!seq_stack || !data)
        return ERR;
    
    // 判断栈是否满
    if (seq_stack -> m_size == STACK_MAX)
        return ERR;
    seq_stack -> data[seq_stack -> m_size] = data;
    // 更新栈大小
    seq_stack -> m_size ++;

    return True;
}

void *pop_seq_stack(struct SeqStack *seq_stack)
{
    if (!seq_stack)
        return NULL;

    if (seq_stack -> m_size == 0)
        return NULL;

    void *data = seq_stack -> data[seq_stack -> m_size - 1];
    seq_stack -> data[seq_stack -> m_size -1] = NULL;
    seq_stack -> m_size --;
    return data;
}

void *top_seq_seq_stack(struct SeqStack *seq_stack)
{
    if (!seq_stack)
        return NULL;

    if (seq_stack -> m_size == 0)
        return NULL;

    void *data = seq_stack -> data[0];
    return data;
}

int size_seq_stack(struct SeqStack *seq_stack)
{
    if (!seq_stack)
        return ERR;

    return seq_stack -> m_size;
}

int is_empty_seq_stack(struct SeqStack *seq_stack)
{
    if (!seq_stack)
        return ERR;

    if (seq_stack -> m_size == 0)
        return True;
    return False;
}

int destroy_seq_stack(struct SeqStack *seq_stack)
{
    if (!seq_stack)
        return ERR;

    free(seq_stack);
    seq_stack = NULL;
    return True;
}

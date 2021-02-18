#include <stdlib.h>
#include "kael_ds.h"
#include <string.h>

struct SeqStack *init_stack()
{
    struct SeqStack *stack = malloc(sizeof(struct SeqStack));
    if (!stack)
        return NULL;

    // 清空数组中的每个元素
    memset(stack -> data, 0, sizeof(void *) * STACK_MAX);
    stack -> m_size = 0;

    return stack;
}

int push_stack(struct SeqStack *stack, void *data)
{
    if (!stack || !data)
        return ERR;
    
    // 判断栈是否满
    if (stack -> m_size == STACK_MAX)
        return ERR;
    stack -> data[stack -> m_size] = data;
    // 更新栈大小
    stack -> m_size ++;

    return True;
}

void *pop_stack(struct SeqStack *stack)
{
    if (!stack)
        return NULL;

    if (stack -> m_size == 0)
        return NULL;

    void *data = stack -> data[stack -> m_size - 1];
    stack -> data[stack -> m_size -1] = NULL;
    stack -> m_size --;
    return data;
}

void *top_seq_stack(struct SeqStack *stack)
{
    if (!stack)
        return NULL;

    if (stack -> m_size == 0)
        return NULL;

    void *data = stack -> data[0];
    return data;
}

int size_stack(struct SeqStack *stack)
{
    if (!stack)
        return ERR;

    return stack -> m_size;
}

int is_empty_stack(struct SeqStack *stack)
{
    if (!stack)
        return ERR;

    if (stack -> m_size == 0)
        return True;
    return False;
}

int destroy_stack(struct SeqStack *stack)
{
    if (!stack)
        return ERR;

    free(stack);
    stack = NULL;
    return True;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person2
{
    char name[64];
    int age;
};


void test_stack_op()
{
    struct SeqStack *stack = init_seq_stack();

    printf("当前的大小为: %d\n", stack -> m_size);

    // 准备5个person数据
    struct Person2 p1 = {"亚索1", 18};
    struct Person2 p2 = {"亚索2", 18};
    struct Person2 p3 = {"亚索3", 18};
    struct Person2 p4 = {"亚索4", 18};
    struct Person2 p5 = {"亚索5", 18};
    struct Person2 p6 = {"亚索6", 18};

    push_seq_stack(stack, &p1);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_seq_stack(stack, &p2);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_seq_stack(stack, &p3);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_seq_stack(stack, &p4);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_seq_stack(stack, &p5);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_seq_stack(stack, &p6);
    printf("当前的大小为: %d\n", stack -> m_size);

    printf("pop\n");
    struct Person2 *data = (struct Person2*)pop_seq_stack(stack);
    printf("pop = %s, %d\n", data -> name, data -> age);

    int ok =is_empty_seq_stack(stack);
    printf("is empty = %d\n", ok);

    printf("destroy\n");
    destroy_seq_stack(stack);
}

int main()
{
    test_stack_op();
    return 0;
}

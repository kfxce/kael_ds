#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person3
{
    char name[64];
    int age;
};


void test_stack_op()
{
    struct LinkStack *stack = init_link_stack();

    printf("当前的大小为: %d\n", stack -> m_size);

    // 准备5个person数据
    struct Person3 p1 = {"亚索1", 18};
    struct Person3 p2 = {"亚索2", 18};
    struct Person3 p3 = {"亚索3", 18};
    struct Person3 p4 = {"亚索4", 18};
    struct Person3 p5 = {"亚索5", 18};
    struct Person3 p6 = {"亚索6", 18};

    push_link_stack(stack, &p1);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_link_stack(stack, &p2);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_link_stack(stack, &p3);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_link_stack(stack, &p4);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_link_stack(stack, &p5);
    printf("当前的大小为: %d\n", stack -> m_size);

    push_link_stack(stack, &p6);
    printf("当前的大小为: %d\n", stack -> m_size);

    printf("pop\n");
    struct Person3 *data = (struct Person3*)pop_link_stack(stack);
    printf("pop = %s, %d\n", data -> name, data -> age);

    int ok =is_empty_link_stack(stack);
    printf("is empty = %d\n", ok);

    printf("destroy\n");
    destroy_link_stack(stack);
}

int main()
{
    test_stack_op();
    return 0;
}

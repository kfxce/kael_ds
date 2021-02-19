#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person5
{
    char name[64];
    int age;
};


void test_link_queue_op()
{
    struct LinkQueue *link_queue = init_link_queue(10);

    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    // 准备5个person数据
    struct Person5 p1 = {"亚索1", 18};
    struct Person5 p2 = {"亚索2", 18};
    struct Person5 p3 = {"亚索3", 18};
    struct Person5 p4 = {"亚索4", 18};
    struct Person5 p5 = {"亚索5", 18};
    struct Person5 p6 = {"亚索6", 18};

    en_link_queue(link_queue, &p1);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    en_link_queue(link_queue, &p2);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    en_link_queue(link_queue, &p3);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    en_link_queue(link_queue, &p4);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    en_link_queue(link_queue, &p5);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    en_link_queue(link_queue, &p6);
    printf("当前的大小为: %d\n", size_link_queue(link_queue));

    printf("de\n");
    struct Person5 *data = (struct Person5*)de_link_queue(link_queue);
    printf("de = %s, %d\n", data -> name, data -> age);

    int ok =is_empty_link_queue(link_queue);
    printf("is empty = %d\n", ok);

    printf("destroy\n");
    destroy_link_queue(link_queue);
}

int main()
{
    test_link_queue_op();
    return 0;
}

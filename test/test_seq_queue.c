#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person4
{
    char name[64];
    int age;
};


void test_seq_queue_op()
{
    struct SeqQueue *seq_queue = init_seq_queue(10);

    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    // 准备5个person数据
    struct Person4 p1 = {"亚索1", 18};
    struct Person4 p2 = {"亚索2", 18};
    struct Person4 p3 = {"亚索3", 18};
    struct Person4 p4 = {"亚索4", 18};
    struct Person4 p5 = {"亚索5", 18};
    struct Person4 p6 = {"亚索6", 18};

    en_seq_queue(seq_queue, &p1);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    en_seq_queue(seq_queue, &p2);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    en_seq_queue(seq_queue, &p3);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    en_seq_queue(seq_queue, &p4);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    en_seq_queue(seq_queue, &p5);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    en_seq_queue(seq_queue, &p6);
    printf("当前的大小为: %d\n", size_seq_queue(seq_queue));

    printf("de\n");
    struct Person4 *data = (struct Person4*)de_seq_queue(seq_queue);
    printf("de = %s, %d\n", data -> name, data -> age);

    int ok =is_empty_seq_queue(seq_queue);
    printf("is empty = %d\n", ok);

    printf("destroy\n");
    destroy_seq_queue(seq_queue);
}

int main()
{
    test_seq_queue_op();
    return 0;
}

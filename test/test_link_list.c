#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person1
{
    char name[64];
    int age;
};

BOOL compare_callback11(void *data1, void *data2)
{
    struct Person1 *p1 = data1;
    struct Person1 *p2 = data2;

    if(strcmp(p1 -> name, p2 -> name) == 0 && p1 -> age == p2 -> age)
        return True;
    else
        return False;
}

void callback1(void *data)
{
    struct Person1 *p = data;
    printf("姓名: %s, 年龄：%d\n", p -> name, p -> age);
}

void test_init_insert_print_delete()
{
    struct LinkList *link_list = init_link_list();

    printf("当前的大小为: %d\n", link_list -> m_size);

    // 准备5个person数据
    struct Person1 p1 = {"亚索1", 18};
    struct Person1 p2 = {"亚索2", 18};
    struct Person1 p3 = {"亚索3", 18};
    struct Person1 p4 = {"亚索4", 18};
    struct Person1 p5 = {"亚索5", 18};
    struct Person1 p6 = {"亚索6", 18};

    // 将数据插入到链表中
    insert_link_list(link_list, 0, &p1);
    printf("当前的大小为: %d\n", link_list -> m_size);

    insert_link_list(link_list, 0, &p2);
    printf("当前的大小为: %d\n", link_list -> m_size);

    insert_link_list(link_list, 0, &p3);
    printf("当前的大小为: %d\n", link_list -> m_size);

    insert_link_list(link_list, 0, &p4);
    printf("当前的大小为: %d\n", link_list -> m_size);

    insert_link_list(link_list, 0, &p5);
    printf("当前的大小为: %d\n", link_list -> m_size);

    insert_link_list(link_list, 0, &p6);
    printf("当前的大小为: %d\n", link_list -> m_size);

    print_link_list(link_list, callback1);


    // 删除第0个位置的元素
    printf("删除第0个位置的元素\n");
    remove_by_pos_link_list(link_list, 0);
    print_link_list(link_list, callback1);

    printf("删除第0个位置的元素\n");
    remove_by_pos_link_list(link_list, 0);
    print_link_list(link_list, callback1);


    /*
    // 根据元素值删除元素
    printf("删除元素p1\n");
    remove_by_value_link_list(link_list, &p1, compare_callback11);
    print_link_list(link_list, callback1);

    printf("销毁数组\n");
    destroy_link_list(link_list);

    ////访问一个被NULL的指针为导致段错误
    print_link_list(link_list, callback1); 
    */
}

int main()
{
    test_init_insert_print_delete();
    return 0;
}

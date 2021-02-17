#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../kael_ds-src/kael_ds.h"

struct Person
{
    char name[64];
    int age;
};

int compare_callback(void *data1, void *data2)
{
    struct Person *p1 = data1;
    struct Person *p2 = data2;

    if(strcmp(p1 -> name, p2 -> name) == 0 && p1 -> age == p2 -> age)
        return True;
    else
        return False;
}

void callback(void *data)
{
    struct Person *p = data;
    printf("姓名: %s, 年龄：%d\n", p -> name, p -> age);
}

void test_init_insert_print_delete()
{
    // 创建动态数组
    struct DynamicArray *dynamic_array = init_dynamic_array(5);

    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    // 准备5个person数据
    struct Person p1 = {"亚索1", 18};
    struct Person p2 = {"亚索2", 18};
    struct Person p3 = {"亚索3", 18};
    struct Person p4 = {"亚索4", 18};
    struct Person p5 = {"亚索5", 18};
    struct Person p6 = {"亚索6", 18};

    // 将数据插入到动态数组中
    insert_dynamic_array(dynamic_array, 0, &p1);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    insert_dynamic_array(dynamic_array, 0, &p2);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    insert_dynamic_array(dynamic_array, 0, &p3);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    insert_dynamic_array(dynamic_array, 0, &p4);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    insert_dynamic_array(dynamic_array, 0, &p5);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    insert_dynamic_array(dynamic_array, 0, &p6);
    printf("当前的容量为: %d\n", dynamic_array -> m_capacity);

    print_dynamic_array(dynamic_array, callback);


    // 删除第0个位置的元素
    printf("删除第0个位置的元素\n");
    remove_by_pos_dynamic_array(dynamic_array, 0);
    print_dynamic_array(dynamic_array, callback);

    printf("删除第0个位置的元素\n");
    remove_by_pos_dynamic_array(dynamic_array, 0);
    print_dynamic_array(dynamic_array, callback);


    // 根据元素值删除元素
    printf("删除元素p1\n");
    remove_by_value_dynamic_array(dynamic_array, &p1, compare_callback);
    print_dynamic_array(dynamic_array, callback);

    printf("销毁数组\n");
    destroy_dynamic_array(dynamic_array);
    print_dynamic_array(dynamic_array, callback);
}

int main()
{
    test_init_insert_print_delete();
    return 0;
}

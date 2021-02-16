#include "kael_ds.h"
#include <stdlib.h>
#include <string.h>



/* 初始化数组
 *
 * param int capacity: 数组的容量
 *
 * return struct DynamicArray *: 动态数组结构体指针
 *
 * 注意：如果返回为NULL则表示初始化失败
 */
struct DynamicArray * init_dynamic_array(int capacity)
{
        if (capacity <= 0)
        {
                return NULL;
        }
        struct DynamicArray *dynamic_array = malloc(sizeof(struct DynamicArray));
        // 判断内存是否申请成功
        if (dynamic_array == NULL)
        {
                return NULL;
        }

        // 设置容量
        dynamic_array -> m_capacity = capacity;
        // 设置大小
        dynamic_array -> m_size = 0;

        // 维护在堆区的数组指针
        dynamic_array -> paddr = malloc(sizeof(void *) * dynamic_array -> m_capacity);

        // 判断内存是否申请成功
        if (dynamic_array -> paddr == NULL)
        {
                free(dynamic_array);
                return NULL;
        }

        return dynamic_array;
}


/* 插入功能
 *
 * param struct DynamicArray *dynamic_array: 被插入新元素的动态数组指针
 * param int pos: 被插入动态数组的位置
 * param void *data: 被插入动态数组的新元素
 *
 * return int: True：成功，False：失败
 */
int insert_dynamic_array(struct DynamicArray *dynamic_array, int pos, void *data)
{
        if (dynamic_array == NULL)
        {
                return False; 
        }

        if (data == NULL)
        {
                return False;
        }

        // 无效的位置
        if (pos < 0 || pos > dynamic_array -> m_size)
        {
                return False;
        }

        // 先判断是否已经满了，如果满则开辟
        if (dynamic_array -> m_size >= dynamic_array -> m_capacity)
        {
                // 申请一个更大的空间
                int new_capacity = dynamic_array -> m_capacity * 2;
                // 创建新空间
                void ** new_space = malloc(sizeof(void *) * new_capacity);
                if (new_space == NULL)
                {
                        return False;
                }
                // 将原有数据拷贝到新空间下
                memcpy(new_space, dynamic_array -> paddr, sizeof(void *) * dynamic_array -> m_capacity);
                // 释放原有空间
                free(dynamic_array -> paddr);
                // 更新指针指向
                dynamic_array -> paddr = new_space;
                // 更新指针容量大小
                dynamic_array -> m_capacity = new_capacity;
        }

        // 插入新的元素
        // 从最后一个位置开始依次移动数据
        for (int i = dynamic_array -> m_size - 1; i >= pos; i--)
        {
                dynamic_array -> paddr[i + 1] = dynamic_array -> paddr[i];
        }

        // 将新元素插入到指定位置
        dynamic_array -> paddr[pos] = data;

        // 更新大小
        dynamic_array -> m_size ++;

        return True;
}


/* 遍历动态数组
 */
void print_dynamic_array(struct DynamicArray *dynamic_array, void(*callback)(void *))
{
    if (dynamic_array == NULL)
    {
        return;
    }
    int i;
    for (i = 0; i < dynamic_array -> m_size; i++)
    {
        callback(dynamic_array -> paddr[i]);
    }
}

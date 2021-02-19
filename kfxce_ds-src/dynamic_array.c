#include "kael_ds.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct DynamicArray * init_dynamic_array(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }
    struct DynamicArray *dynamic_array = malloc(sizeof(struct DynamicArray));
    // 判断内存是否申请成功
    if (!dynamic_array)
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
    if (!dynamic_array -> paddr)
    {
        free(dynamic_array);
        return NULL;
    }

    return dynamic_array;
}


int insert_dynamic_array(struct DynamicArray *dynamic_array, int pos, void *data)
{
    if (!dynamic_array || !data)
    {
        return ERR; 
    }


    // 无效的位置
    if (pos < 0 || pos > dynamic_array -> m_size)
    {
        return ERR;
    }

    // 先判断是否已经满了，如果满则开辟
    if (dynamic_array -> m_size >= dynamic_array -> m_capacity)
    {
        // 申请一个更大的空间
        int new_capacity = dynamic_array -> m_capacity * 2;
        // 创建新空间
        void ** new_space = malloc(sizeof(void *) * new_capacity);
        if (!new_space)
        {
                return ERR;
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


void print_dynamic_array(struct DynamicArray *dynamic_array, void(*callback)(void *))
{
    if (!dynamic_array)
        return;
    for (int i = 0; i < dynamic_array -> m_size; i++)
        callback(dynamic_array -> paddr[i]);
}

int remove_by_pos_dynamic_array(struct DynamicArray *dynamic_array, int pos)
{
    // 如果数组指针为NULL
    if (!dynamic_array)
        return ERR;

    // 无效的位置
    if (pos < 0 || pos > dynamic_array -> m_size - 1)
        return ERR;

    int i;
    // 从pos开始到数组的结尾的数据进行前移
    for (i = pos; i < dynamic_array -> m_size - 1; i++)
        dynamic_array -> paddr[i] = dynamic_array -> paddr[i + 1];

    
    // 将删除的元素的数组位置置空
    dynamic_array -> paddr[dynamic_array -> m_size - 1] = NULL;

    // 数组大小减一
    dynamic_array -> m_size --;
    
    return True;
}


int remove_by_value_dynamic_array(struct DynamicArray *dynamic_array, void *data, 
        int(*compare_callback)(void *, void*))
{
    if (!dynamic_array || !data)
        return ERR;

    int i;
    for (i = 0; i < dynamic_array -> m_size; i++)
    {
        if(True == compare_callback(dynamic_array -> paddr[i], data))
        {
            if(True == remove_by_pos_dynamic_array(dynamic_array, i))
                return True;
            else
                return False;
        }
    }
    return False;
}

int destroy_dynamic_array(struct DynamicArray *dynamic_array)
{
    if (!dynamic_array)
        return False;
    if (dynamic_array -> paddr)
    {
        free(dynamic_array -> paddr);
        dynamic_array -> paddr = NULL;
    }

    free(dynamic_array);
    dynamic_array = NULL;
    return True;
}


void *get_by_pos_dynamic_array(struct DynamicArray *dynamic_array, int pos)
{
    if (!dynamic_array)
        return NULL;

    if (pos < 0 || pos > dynamic_array -> m_size - 1)
        return NULL;

    void *data = dynamic_array -> paddr[pos];
    return data;
}


int is_empty_dynamic_array(struct DynamicArray *dynamic_array)
{
    if (!dynamic_array)
        return ERR;
    if (dynamic_array -> m_size == 0)
        return True;
    return False;
}

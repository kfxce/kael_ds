#include <stdlib.h>
#include <string.h>
#include "kael_ds.h"


/* 初始化链表
 *
 * return struct LinkList *: 返回结构体链表指针, 返回NULL则为失败
 */
struct LinkList * init_link_list()
{
    struct LinkList *link_list = malloc(sizeof(struct LinkList));
    if (!link_list) 
        return NULL;

    link_list -> header.data = NULL;
    link_list -> header.next = NULL;
    
    link_list -> m_size = 0;

    return link_list;
}

/* 向链表插入节点
 *
 * param struct LinkList *link_list: 链表结构体指针
 * param int pos: 要插入的位置
 * param void *data: 要插入的数据
 *
 * return BOOL；True成功，False失败
 */
BOOL insert_link_list(struct LinkList *link_list, int pos, void *data)
{
    if(!link_list || !data)
        return False;
    
    // 无效位置尾插
    if (pos < 0 || pos > link_list -> m_size)
    {
        pos = link_list -> m_size;
    }

    // 创建临时节点
    struct LinkNode *current_link_node = &link_list -> header;
    int i;

    // 通过循环找到插入位置的前驱节点
    for (i = 0; i < pos; i++)
    {
        current_link_node = current_link_node -> next;
    }
    struct LinkNode *new_link_node = malloc(sizeof(struct LinkNode));
    // 申请内存失败
    if(!new_link_node)
        return False;

    new_link_node -> data = data;
    new_link_node -> next = NULL;

    // 将新节点插入到链表中
    new_link_node -> next = current_link_node -> next;
    current_link_node -> next = new_link_node;

    // 更新链表长度
    link_list -> m_size ++;
    return True;
}


/* 遍历链表
 * 
 * param struct LinkList *link_list: 链表结构体指针
 * param callbck: 回调函数
 */
void print_link_list(struct LinkList *link_list, void(*callback)(void *))
{
    if (!link_list)
        return;

    struct LinkNode *current_link_node = link_list -> header.next;
    int i;
    for (i = 0; i < link_list -> m_size; i++)
    {
        callback(current_link_node -> data);
        current_link_node = current_link_node -> next;
    }
}


/* 删除节点
 * param struct LinkList *link_list: 链表结构体指针
 * param int pos: 删除的位置
 *
 * return BOOL: 成功返回True, 失败返回False
 */
BOOL remove_by_pos_link_list(struct LinkList *link_list, int pos)
{
    if (!link_list) 
        return False;

    if (pos < 0 || pos > link_list -> m_size - 1)
        return False;

    struct LinkNode *current_link_node = &link_list -> header;
    int i;
    for (i = 0; i < pos; i++)
        current_link_node = current_link_node -> next;

    current_link_node -> next = current_link_node -> next -> next;

    // 释放删除掉的节点
    free(del_link_node);
    del_link_node = NULL;

    // 更新链表长度
    link_list -> m_size --;

    return True; 
}

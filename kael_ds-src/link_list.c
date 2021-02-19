#include <stdlib.h>
#include <string.h>
#include "kael_ds.h"


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

int insert_link_list(struct LinkList *link_list, int pos, void *data)
{
    if(!link_list || !data)
        return False;
    
    // 无效位置尾插
    if (pos < 0 || pos > link_list -> m_size)
    {
        pos = link_list -> m_size;
    }

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

void print_link_list(struct LinkList *link_list, void(*callback)(void *))
{
    if (!link_list)
        return;

    if (link_list -> m_size == 0)
        return;

    struct LinkNode *current_link_node = link_list -> header.next;
    int i;
    for (i = 0; i < link_list -> m_size; i++)
    {
        callback(current_link_node -> data);
        current_link_node = current_link_node -> next;
    }
}

int remove_by_pos_link_list(struct LinkList *link_list, int pos)
{
    if (!link_list) 
        return False;

    if (pos < 0 || pos > link_list -> m_size - 1)
        return False;

    // 找到要删除节点的前驱节点
    struct LinkNode *current_link_node = &link_list -> header;
    int i;
    for (i = 0; i < pos; i++)
        current_link_node = current_link_node -> next;

    // 要删除的节点
    struct LinkNode *del_link_node = current_link_node -> next;
    
    // 建立前驱节点和要删除节点的next节点的连接
    current_link_node -> next = del_link_node -> next;

    // 释放删除掉的节点
    free(del_link_node);
    del_link_node = NULL;

    // 更新链表长度
    link_list -> m_size --;

    return True; 
}

int remove_by_value_link_list(struct LinkList *link_list, void *data, int(*compare_callback)(void *, void *))
{
    if (!link_list || !data)
        return False;

    struct LinkNode *prev_link_node = &link_list -> header;
    struct LinkNode *current_link_node = prev_link_node -> next;

    for (int i = 0; i < link_list -> m_size; i++)
    {
        if (True == compare_callback(current_link_node -> data, data))
        {
            prev_link_node -> next = current_link_node -> next;
            free(current_link_node);
            current_link_node = NULL;
            
            link_list -> m_size --;
            return True;
        }

        prev_link_node = current_link_node;
        current_link_node = current_link_node -> next;
    }

    return False;
}

int clear_link_list(struct LinkList *link_list)
{
    if (!link_list)
        return False;

    struct LinkNode *current_link_node = link_list -> header.next;
    
    for(int i = 0; i < link_list -> m_size; i++)
    {
        struct LinkNode *next_link_node = current_link_node -> next;
        free(current_link_node);
        current_link_node = next_link_node;
    }

    link_list -> header.next = NULL;
    link_list -> m_size = 0;

    return True;
}

int len_link_list(struct LinkList *link_list)
{
    if (!link_list)
        return ERR;
    return link_list -> m_size;
}

int is_empty_link_list(struct LinkList *link_list)
{
    if (!link_list)
        return ERR;

    if (link_list -> m_size == 0)
        return True;
    return False;
}


int destroy_link_list(struct LinkList *link_list)
{
    if (!link_list)
        return ERR;

    int success = clear_link_list(link_list);
    if (success == True)
    {
        free(link_list);
        link_list = NULL;
        return True;
    }
    else
    {
        return success;
    }
}


void *get_by_pos_link_list(struct LinkList *link_list, int pos)
{
    if (!link_list)
        return NULL;

    if (pos < 0 || pos > link_list -> m_size - 1)
        return NULL;

    // 找到要删除节点的前驱节点
    struct LinkNode *current_link_node = &link_list -> header;
    for (int i = 0; i < pos; i++)
        current_link_node = current_link_node -> next;

    return current_link_node -> data; 
}

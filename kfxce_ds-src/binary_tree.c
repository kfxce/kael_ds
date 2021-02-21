#include <stdlib.h>
#include "kfxce_ds.h"


void left_recursion_binary_tree(struct BinaryTree *binary_tree,
        void(*callback)(void *))
{
    if (!binary_tree)
        return;

    void *data = binary_tree -> data;
    struct BinaryTree *left_child = binary_tree -> left_child;
    struct BinaryTree *right_child = binary_tree -> right_child;
    callback(data); 

    left_recursion_binary_tree(left_child, callback);
    left_recursion_binary_tree(right_child, callback);
}

void middle_recursion_binary_tree(struct BinaryTree *binary_tree, 
        void(*callback)(void *))
{
    if (!binary_tree)
        return;

    void *data = binary_tree -> data;
    struct BinaryTree *left_child = binary_tree -> left_child;
    struct BinaryTree *right_child = binary_tree -> right_child;

    middle_recursion_binary_tree(left_child, callback);
    callback(data); 
    middle_recursion_binary_tree(right_child, callback);
}

void right_recursion_binary_tree(struct BinaryTree *binary_tree, 
        void(*callback)(void *))
{
    if (!binary_tree)
        return;

    void *data = binary_tree -> data;
    struct BinaryTree *left_child = binary_tree -> left_child;
    struct BinaryTree *right_child = binary_tree -> right_child;

    right_recursion_binary_tree(left_child, callback);
    right_recursion_binary_tree(right_child, callback);
    callback(data); 
}

void stat_leaf_num_binary_tree(struct BinaryTree *binary_tree, int *num)
{
    if (!binary_tree)
        return;

    struct BinaryTree *left_child = binary_tree -> left_child;
    struct BinaryTree *right_child = binary_tree -> right_child;
    
    if (left_child == NULL && right_child == NULL)
        (*num)++;

    stat_leaf_num_binary_tree(left_child, num); 
    stat_leaf_num_binary_tree(right_child, num); 
}

int deepth_binary_tree(struct BinaryTree *binary_tree)
{
    if (!binary_tree)
        return 0;

    int left_tree_height = deepth_binary_tree(binary_tree -> left_child);
    int right_tree_height = deepth_binary_tree(binary_tree -> right_child);
    int height;

    if (left_tree_height > right_tree_height)
        height = left_tree_height + 1;
    else
        height = right_tree_height + 1;

    return height;
}

struct BinaryTree *copy_binary_tree(struct BinaryTree *binary_tree)
{
    if (!binary_tree)
        return NULL;

    struct BinaryTree *left_child_binary_tree = 
        copy_binary_tree(binary_tree -> left_child);
    struct BinaryTree *right_child_binary_tree = 
        copy_binary_tree(binary_tree -> right_child);

    struct BinaryTree *new_binary_tree = malloc(sizeof(struct BinaryTree));
    new_binary_tree -> left_child = left_child_binary_tree;
    new_binary_tree -> right_child = right_child_binary_tree;
    new_binary_tree -> data = binary_tree -> data;

    return new_binary_tree;
}

int free_binary_tree(struct BinaryTree *binary_tree)
{
    if (!binary_tree)
        return ERR;

    free_binary_tree(binary_tree -> left_child);
    free_binary_tree(binary_tree -> right_child);

    free(binary_tree);
    binary_tree = NULL;
    return True;
}

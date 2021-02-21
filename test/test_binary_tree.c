#include "../kfxce_ds-src/kfxce_ds.h"
#include <stdio.h>
#include <stdlib.h>


void my_callback(void *data)
{
    if (!data)
        return;
    int i = *(int *)data;
    printf("%d\n", i);
}

void test()
{
    int i = 0;
    int j = 1;
    int k = 2;
    struct BinaryTree *root, *left, *right, *copy;
    root = malloc(sizeof(struct BinaryTree));
    left = malloc(sizeof(struct BinaryTree));
    right = malloc(sizeof(struct BinaryTree));

    root -> data = &i;
    root -> left_child = left;
    root -> right_child = right;

    left -> data = &j;
    left -> left_child = NULL;
    left -> right_child = NULL;

    right -> data = &k;
    right -> left_child = NULL;
    right -> right_child = NULL;

    //left_recursion_binary_tree(root, my_callback); 
    //middle_recursion_binary_tree(root, my_callback); 
    right_recursion_binary_tree(root, my_callback); 

    int leaf_num = 0;
    stat_leaf_num_binary_tree(root, &leaf_num);
    printf("leaf num = %d\n", leaf_num);

    int deepth = deepth_binary_tree(root);
    printf("deepth = %d\n", deepth);

    copy = copy_binary_tree(root);
    right_recursion_binary_tree(copy, my_callback); 


    free_binary_tree(root);
    free_binary_tree(copy);
}

int main()
{
    test();
    return 0;
}

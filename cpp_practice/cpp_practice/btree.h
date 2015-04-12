//
//  btree.h
//  cpp_practice
//
//  Created by Xuan Liu on 3/2/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#ifndef cpp_practice_btree_h
#define cpp_practice_btree_h
#include <stdlib.h>
#include <stdio.h>

struct binary_tree
{
    int data;
    binary_tree *left;
    binary_tree *right;
};

typedef binary_tree btree;

// building a tree
btree* add_leave(btree *root, int value)
{
    btree *curr, *newnode;
    curr = root;
    newnode = new btree;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    else
    {
        while(curr != NULL)
        {
            if (value >= curr->data)
            {
                if (curr->right == NULL)
                {
                    newnode->right = NULL;
                    curr->right = newnode;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->left == NULL)
                {
                    curr->left = newnode;
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }
        return root;
    }
}


btree* build_tree(btree *root, int size, int seed)
{
    printf("Building a binary tree.\n");
    srand(seed);
    int value;
    for (int i = 0; i < size; i++)
    {
        value = rand()%40 + i;
        printf("adding %d\n", value);
        root = add_leave(root, value);
    }
    return root;
}

void print_btree(btree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        print_btree(root->left);
        print_btree(root->right);
    }
    
}

#endif

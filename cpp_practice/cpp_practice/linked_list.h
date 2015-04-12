//
//  linked_list.h
//  cpp_practice
//
//  Created by Xuan Liu on 2/24/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#ifndef cpp_practice_linked_list_h
#define cpp_practice_linked_list_h
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

// singly linked list
struct nodeType {
    int data;
    nodeType *next;
};

typedef nodeType node;

// generate a linked list forward
node* gen_list(node *head, int size, int seed)
{
    printf("Generate a linked list with size %d.\n", size);
    srand(seed);
    node *curr, *last;
    last = head;
    for (int i = 0; i < size; i++)
    {
        curr = new node;
        curr->data = rand()%10;
        curr->next = NULL;
        if (head == NULL)
        {
            head = curr;
        }
        else
        {
            last->next = curr;
        }
        last = curr;
        
    }
    return head;
}

// generate a linked list backword
node* gen_list_backward(node* head, int size, int seed)
{
    printf("Genering a linked list in size %d backward\n", size);
    srand(seed);
    node* curr;
    for (int i = 0; i < size; i++)
    {
        curr = new node;
        curr->data = rand()%100 + 1;
        curr->next = head;
        head = curr;
    }
    return head;
}

// reverse a list
node* reverse_list(node *head)
{
    node *pre, *curr, *next;
    pre = NULL;
    curr = head;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

// print the list
void print_list(node *head)
{
    printf("Printing a linked list:\n");
    node *curr;
    curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// search a node with a given value
node* search_list(node* head, int value)
{
    node* curr;
    curr = head;
    while(curr->next != NULL)
    {
        if (curr->data == value)
        {
            break;
        }
        curr = curr->next;
    }
    return curr;
}


// insert a new item to a linked list, and this new item is not inserted as first node
void insert_item(node *previous, int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    if (previous->next != NULL)
    {
        newnode->next = previous->next;
        previous->next = newnode;
    }
    else
    {
        previous->next = newnode;
    }
}

// insert a new node with a given value to as the first node in the list
node* insert_first(node *head, int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    if (head != NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        head = newnode;
    }
    return head;
}

// Detele a node with a value
node* delete_node(node* head, int value)
{
    printf("Deleting %d\n", value);
    if (head == NULL)
    {
        printf("Linked list is empty, no need to delete!\n");
    }
    else
    {
        node *curr;
        curr = head;
        if (curr->data == value)
        {
            head = curr->next;
            delete curr;
        }
        else
        {
            while(curr->next != NULL)
            {
                if (curr->next->data == value)
                {
                    node *temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                    break;
                }
                else
                {
                    curr = curr->next;
                }
            }
            if (curr->next == NULL)
            {
                printf("%d is not in the list, nothing to delete!\n", value);
            }
        }
        
    }
    return head;
}

// insert an value as the ith node in the linked list
node* insert_by_index(node* head, int i, int value)
{
    if (i <=0)
    {
        printf("index must be greater 0, no changes!\n");
        return head;
    }
    node *curr, *newnode;
    int count;
    curr = head;
    count = 1;
    if (i == 1)
    {
        newnode = new node;
        newnode->data = value;
        newnode->next = curr->next;
        head = newnode;
        return head;
    }
    else
    {
        while (curr != NULL)
        {
            if (count == i-1)
            {
                newnode = new node;
                newnode->data = value;
                newnode->next = curr->next;
                curr->next = newnode;
                break;
            }
            else
            {
                if (curr->next == NULL && i > count)
                {
                    printf("Index is greater than the length of the list, insert to the end");
                    newnode = new node;
                    newnode->data = value;
                    newnode->next = NULL;
                    curr->next = newnode;
                    break;
                }
                else
                {
                    curr = curr->next;
                    count++;
                }

            }
        }
        //delete newnode;
        return head;
    }
}


// doubly linked list
struct db_linkedlist
{
    int data;
    db_linkedlist *previous;
    db_linkedlist *next;
};

typedef db_linkedlist db_list;

// generate a linked list forward
db_list* gen_dblist(db_list *head, int size, int seed)
{
    printf("Generate a doubly linked list with size %d.\n", size);
    srand(seed);
    db_list *curr, *last;
    //last = head;
    for (int i = 0; i < size; i++)
    {
        curr = new db_list;
        curr->data = rand()%100 + 1;
        curr->next = NULL;
        curr->previous = NULL;
        
        if (head == NULL)
        {
            head = curr;
            
        }
        else
        {
            last->next = curr;
            curr->previous = last;
        }
        last = curr;
        
    }
    return head;
}

// print the list
void print_dblist(db_list *head)
{
    printf("Printing a doubly linked list:\n");
    db_list *curr;
    curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

db_list* search_dblist(db_list* head, int value)
{
    db_list* curr;
    curr = head;
    while(curr->next != NULL)
    {
        if (curr->data == value)
        {
            break;
        }
        curr = curr->next;
    }
    return curr;
}

// insert a new item to a doubly linked list, and this new item is not inserted as first node
void insert_dbitem(db_list *pre, int value)
{
    db_list *newnode = new db_list;
    newnode->data = value;
    newnode->next = NULL;
    newnode->previous = NULL;
    if (pre->next != NULL)
    {
        pre->next->previous = newnode;
        newnode->next = pre->next;
        newnode->previous = pre;
        pre->next = newnode;
    }
    else
    {
        pre->next = newnode;
        newnode->previous = pre;
    }
}

#endif

//
//  main.cpp
//  cpp_practice
//
//  Created by Xuan Liu on 2/24/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#define SIZE 10
#define HIGHT 4
#define WIDTH 8

#include <iostream>
#include <time.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

//my defined header file
#include "array.h"
#include "linked_list.h"
#include "btree.h"
#include "search_algorithm.h"
#include "sorting.h"
#include "process_string.h"
#include "leetcode_sol.h"

using namespace std;


// check if while(1) or while(2) is faster
int checkFaster()
{
	int a=1;
	clock_t begin,end;
    
	while(a)
	{
		begin=clock();
        for (int i = 0; i<1000000;i++)
        {
            continue;
        }
		a=0;
	}
	end=clock();
	double time_spent1=(double)(end-begin)/CLOCKS_PER_SEC;
	a=2;
	while(a)
	{
		begin=clock();
        for (int i = 0; i<1000000;i++)
        {
            continue;
        }
		a=0;
	}
	end=clock();
	double time_spent2=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("%lf, %lf\n", time_spent1, time_spent2);
	return (time_spent1>time_spent2?1:0);
}

void *runner(int *value)
{
    int i, upper;
    upper = *value;
    int sum = 0;
    
    for (i = 0;i<upper; i++)
    {
        sum = sum + i;
    }
    pthread_exit(0);
    
}


/*------------ leetcode solution --------*/
/*
 Problem 19: Remove Nth Node From End of List
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example:
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
void delFromEnd()
{
    int a[3] = {1,2,3};
    int n = 1;
    node2 *node_list, *new_list;
    node_list = NULL;
    new_list = NULL;
    node_list = gen_list2(node_list, a, 3);
    new_list = removeNthFromEnd(node_list, n);
    print_list(new_list);
}


/*
 Problem 2: Add two numbers
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
*/
void add2num()
{
    node2 *l1, *l2, *sum;
    int a1[1] = {5};
    int a2[1] = {5};
    l1 = NULL;
    l2 = NULL;
    //l1 = gen_list(l1, 2, 11);
    //l2 = gen_list(l2, 1, 19);
    l1 = gen_list2(l1, a1, 1);
    l2 = gen_list2(l2, a2, 1);
    print_list(l1);
    print_list(l2);
    
    sum = addTwoNumbers(l1, l2);
    print_list(sum);
}



/*
 Problem 83: delete duplicated nodes from sorted linked list
 
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
*/
void deleteDuplicatedNodes(){
    node2 *l,*new_list;
    int a[1] = {1};
    l = NULL;
    new_list = NULL;
    l = gen_list2(l, a, 1);
    print_list(l);
    new_list = deleteDuplicates(l);
    print_list(new_list);
}

int main(int argc, const char * argv[])
{
    // generate 1-D array
    int *a;
    int **b;
    a = array_gen(59);
    printarray(a);
    // generate 2-D array
    array_gen2(37);
    b = array_gen2d(101);
    printarray2(b);
    
    // free memory
    delete a;
    delete b;
    
    node *head, *head2, *target;
    // create a new node with value 200
    head = new node;
    head = NULL;
    // generate linked list forward
    head = gen_list(head, 10, 19);
    print_list(head);
    target = search_list(head, 73);
    printf("find target with value %d at %p\n", target->data, target);
    insert_item(target, 200);
    head = insert_first(head, 300);
    head = insert_by_index(head, 11, 100);
    print_list(head);
    head = delete_node(head, 10);
    print_list(head);
    // reverse the list
    printf("reverse the list");
    node *reverse;
    reverse = reverse_list(head);
    print_list(reverse);
    
    // create a linked list backward
    head2 = new node;
    head2 = NULL;
    head2 = gen_list_backward(head2, 10, 19);
    print_list(head2);
    head = insert_by_index(head2, 11, 100);
    print_list(head2);
    
    // create a doubly linked list forward
    db_list *db_head, *target2;
    db_head = new db_list;
    db_head = NULL;
    db_head = gen_dblist(db_head, 10, 29);
    print_dblist(db_head);
    target2 = search_dblist(db_head, 66);
    insert_dbitem(target2, 100);
    print_dblist(db_head);
    
    // build a binary tree in a given size
    btree *root;
    root = NULL;
    root = build_tree(root, 10, 19);
    print_btree(root);
    printf("\n");
    
    
    // binary search
    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    int index;
    index = bsearch(list, 10, 1);
    if (index == -1)
    {
        printf("NOT found\n");
    }
    else
    {
        printf("%d, %d\n", index, list[index]);
    }
    
    int *sublist = new int[5];
    sublist = subarray(list, 3, 7);
    printf("%d\n",sublist[0]);
    
    // track time
    if(checkFaster())
		printf("No while2 is faster\n");
	else
		printf("Yes while1 is faster\n");
    

    // problem 2: add two numbers
    add2num();
    
    // problem 19: delete nth node from the end
    delFromEnd();
    
    // problem 83: delete duplicated nodes from sorted list
    deleteDuplicatedNodes();
    
    return 0;
    

}




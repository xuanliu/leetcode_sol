//
//  leetcode_sol.h
//  cpp_practice
//
//  Created by Xuan Liu on 3/10/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#ifndef cpp_practice_leetcode_sol_h
#define cpp_practice_leetcode_sol_h


/*
 4. You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode node2;
// generate a linked list forward
node2* gen_list(node2 *head, int size, int seed)
{
    printf("Generate a linked list with size %d.\n", size);
    srand(seed);
    node2 *curr, *last;
    last = head;
    for (int i = 0; i < size; i++)
    {
        curr = new node2(0);
        curr->val = rand()%9+1;
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

// generate a linked list forward
node2* gen_list2(node2 *head, int a[], int size)
{
    printf("Generate a linked list with size %d.\n", size);
    node2 *curr, *last;
    last = head;
    for (int i = 0; i < size; i++)
    {
        curr = new node2(0);
        curr->val = a[i];
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

// print the list
void print_list(node2 *head)
{
    printf("Printing a linked list:\n");
    node2 *curr;
    curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}


//Problem 2
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    else if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;
    else
    {
        ListNode *sum, *last, *curr,*l1curr, *l2curr;
        sum = new ListNode(0);
        last = sum;
        int carry;
        carry = 0;
        l1curr = l1;
        l2curr = l2;
        while(l1curr!= NULL && l2curr!= NULL)
        {
            curr = new ListNode(0);
            last->val = (l1curr->val + l2curr->val + carry)%10;
            carry = (l1curr->val + l2curr->val + carry)/10;
            l1curr = l1curr->next;
            l2curr = l2curr->next;
            if (l1curr != NULL && l2curr != NULL)
            {
                last->next = curr;
                last = curr;
            }
        }
        if (l1curr == NULL && l2curr == NULL)
        {
            if (carry != 0)
            {
                curr->val = carry;
                last->next = curr;
                last = curr;
            }
            else
            {
                last = NULL;
            }
            return sum;
        }
        else if (l1curr == NULL)
        {
            while(l2curr != NULL)
            {
                curr = new node2(0);
                curr->val = (l2curr->val + carry)%10;
                carry = (l2curr->val + carry)/10;
                last->next = curr;
                last = curr;
                l2curr = l2curr->next;
            }
            if (carry != 0 && l2curr == NULL)
            {
                curr = new node2(carry%10);
                last->next = curr;
                last = curr;
            }
            return sum;
        }
        else
        {
            while(l1curr != NULL)
            {
                curr = new node2(0);
                curr->val = (l1curr->val + carry)%10;
                carry = (l1curr->val + carry)/10;
                last->next = curr;
                last = curr;
                l1curr = l1curr->next;
            }
            if (carry != 0 && l1curr == NULL)
            {
                curr = new node2(carry%10);
                last->next = curr;
                last = curr;
            }
            return sum;
        }
    }
}

// Problem 19
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *toDel;
    ListNode *curr;
    int gap, count;
    gap = 0, count = 0;
    curr = head;
    toDel = head;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        if (head->next == NULL && n == 1)
        {
            head = NULL;
            return head;
        }
        else
        {
            count++;
            while (curr->next != NULL)
            {
                curr = curr->next;
                count++;
                if (gap < n)
                {
                    gap ++;
                }
                else{
                    toDel = toDel->next;
                }
            }
            if (gap == n){
                ListNode *temp = toDel->next;
                toDel->next = toDel->next->next;
                delete temp;
                
            }
            else if (count == n){
                head = head->next;
                delete toDel;
            }
            return head;
        }
    }
}



/*
 Problem 189
 
 Rotate an array of n elements to the right by k steps.
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

void rotate(int nums[], int n, int k) {
    int *temp = new int[n];
    int new_pos;
    for (int i = 0;i<n;i++)
    {
        temp[i] = nums[i];
    }
    for (int i = 0;i<n;i++)
    {
        new_pos = (i+k)%n;
        nums[new_pos] = temp[i];
    }

}


// problem 83
ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    else {
        ListNode *check, *curr;
        curr = head;
        check = curr->next;
        while (check != NULL)
        {
            if (check->val == curr->val)
            {
                ListNode *temp = NULL;
                temp = check;
                curr->next = check->next;
                check = curr->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
                check = curr->next;
            }
        }
        return head;
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    
}
#endif

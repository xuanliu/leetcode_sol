//
//  search_algorithm.h
//  cpp_practice
//
//  Created by Xuan Liu on 3/3/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#ifndef cpp_practice_search_algorithm_h
#define cpp_practice_search_algorithm_h

int bsearch(int list [], int length, int target)
{
    int start, end, mid;
    start = 0;
    end = length - 1;
    bool found = false;

    while(start<=end)
    {
        mid = (start + end)/2;
        if (target == list[mid])
        {
            found = true;
            break;
        }
        if (target > list[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (found == true)
    {
        return mid;
    }
    else
        return -1;
    
}


int* subarray(int list[], int start, int end)
{
    int *p = list;
    int length;
    length = end - start + 1;
    int *newlist = new int[length];
    newlist = p+start;
    for (int i = 0; i<length; i++)
    {
        newlist[i] = list[start+i];
    }
    return newlist;
}


#endif

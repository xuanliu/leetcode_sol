//
//  array.h
//  cpp_practice
//
//  Created by Xuan Liu on 2/28/15.
//  Copyright (c) 2015 Xuan Liu. All rights reserved.
//

#ifndef cpp_practice_array_h
#define cpp_practice_array_h
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */


int* array_gen(int seed)
{
    // Generate one-dimentioal array with random number
    printf("Generating a one-dimensional array with size %d.\n", SIZE);
    srand(seed);
    int *a = new int[SIZE];
    // initialize one dimensional array
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand()%20 + 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    return a;
}

void array_gen2(int seed)
{
    // Generate a two dimentional array with given dimension information
    printf("Generating a two-dimensional array with size %d by %d.\n", HIGHT, WIDTH);
    srand(seed);
    // initialize two dimensioanl array
    int b[HIGHT][WIDTH];
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            b[i][j] = rand()%30 + 1;
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int** array_gen2d(int seed)
{
    // Generate a two dimentional array with given dimension information
    printf("Generating a two-dimensional array with size %d by %d.\n", HIGHT, WIDTH);
    srand(seed);
    int **p;
    p = new int*[HIGHT];
    for (int i = 0;i < HIGHT; i++)
    {
        p[i] = new int[WIDTH];
        for (int j = 0; j < WIDTH; j++)
        {
            p[i][j] = rand()%30 + 1;
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return p;
    
}

void printarray(int *a)
{
    printf("printing one-dimentional array.\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: %d;",i, a[i]);
    }
    printf("\n");
}

void printarray2(int **a)
{
    printf("printing two-dimentional array.\n");
    for (int i = 0; i < HIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}



#endif

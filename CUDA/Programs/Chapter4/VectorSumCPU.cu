/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation. 
 * Any use, reproduction, disclosure, or distribution of this software 
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 *
 * Please refer to the applicable NVIDIA end user license agreement (EULA) 
 * associated with this source code for terms and conditions that govern 
 * your use of this NVIDIA software.
 * 
 */

#include "../../Common/book.h"
#include <time.h>

#define N 100000000 

void add(int *a, int *b, int *c)
{
    int tid = 0;
    // this is CPU zero, so we start at zero
    while (tid < N)
    {
        c[tid] = a[tid] + b[tid];
        tid += 1;
        // we have one CPU, so we increment by one
    }
}

int main(void)
{
    int *a, *b, *c;
    clock_t start, end;
    double cpu_time_used;    

    a = (int*)malloc(N * sizeof(int));
    b = (int*)malloc(N * sizeof(int));
    c = (int*)malloc(N * sizeof(int));

    // fill the arrays 'a' and 'b' on the CPU
    for (int i = 0; i < N; i++)
    {
        a[i] = -i;
        b[i] = i * 2;
    }

    start = clock();
    add(a, b, c);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("add() took %f seconds to execute \n", cpu_time_used); 
    
    // display the results
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%d + %d = %d\n", a[i], b[i], c[i]);
    // }
    
    return 0;
}
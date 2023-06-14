//
// Created by songwang on 6/9/2023.
//

#include <stdio.h>
#include "BubbleSort.h"
#include "Common.h"


/**
 * @brief : bubble Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : best time ,worst time ,average time : n^2 ; space: 1 ; Stability;
 * */
void bubbleSort(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    for(int i=len;i>1;i--)
    {
        for(int j = 0;j<i-1;j++)
        {
            if(arr[j]>arr[j+1])
                sortSwap(arr,len,j,j+1);
        }
    }
}

/**
 * @brief : bubble Sort After optimization
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : worst time ,average time : n^2 ; best time n ; space: 1 ; Stability;
 * */
void bubbleSort2(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    /* if flag is 1; swap not occur */
    int flag;

    for(int i=len;i>1;i--)
    {
        flag = 1;

        for(int j = 0;j<i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                sortSwap(arr,len,j,j+1);
                flag = 0;
            }
        }
        if(flag) return;
    }
}
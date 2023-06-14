//
// Created by songwang on 6/9/2023.
//

#include "stdio.h"
#include "InsertionSort.h"
#include "Common.h"

/**
 * @brief : Insertion Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : worst time ,average time : n^2 ; best time n ; space: 1 ; Stability;
 * */
void insertionSort(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len <2) return;

    /* if flag == 1 then had exchange */
    int flag = 0;

    for(int i =1;i<len;i++)
    {
        for(int j = i; j>0 && (arr[j]<arr[j-1]) ;j--)
        {
            sortSwap(arr,len,j,j-1);
        }
    }
}

//
// Created by songwang on 6/9/2023.
//

#include "stdio.h"
#include "SelectionSort.h"
#include "Common.h"

/**
 * @brief : selection Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : best time ,worst time ,average time : n^2 ; space: 1; Instability
 * */
void selectionSort(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len <2) return;

    int min;

    for(int i = 0; i<len; i++)
    {
        min = i;
        for(int j = i;j<len;j++) min = (arr[j]<arr[min])? j: min;

        sortSwap(arr, len, i ,min);

#if DEBUG & DEBUG_SELECTIONSORT
        sortPrint(arr,len);
#endif

    }

}

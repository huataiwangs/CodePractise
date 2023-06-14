//
// Created by songwang on 6/9/2023.
//
#include "stdio.h"
#include "HeapSort.h"
#include "Common.h"

/**
 * @brief : Heap Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : best time ,worst time ,average time : nlog2n ; space: 1; Instability
 * */
void heapSort(int* arr,int len)
{
    heapBuilder(arr,len);

    for(int i =len-1;i>=0;i--)
    {
        sortSwap(arr,len,0,i);
        heapify(arr,i,0);
    }
}

/**
 * @brief : Perform heapify with this node and recurse to the bottom
 * @param arr : Input array
 * @param len : Array length
 * @param root : node
 * @return : NULL
 * */
void heapify(int* arr,int len,int root)
{
    /* Security check and recursive termination condition*/
    if(arr == NULL || len<0 || root<0 ||root>=len) return;

    int max = root;
    /* left root */
    max = (2*root+1 < len && arr[2*root+1]>arr[max])?(2*root+1):max;

    /* right root */
    max = (2*root+2 < len && arr[2*root+2]>arr[max])?(2*root+2):max;

    if(max != root)
    {
        sortSwap(arr,len,root,max);

#if DEBUG & DEBUG_HEAPSORT
//        sortPrint(arr,len);
#endif

        heapify(arr,len,max);
    }

}

/**
 * @brief : Construction heap. proceed heapify, starting from the parent node of the last node to root
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void heapBuilder(int* arr,int len)
{
    for(int i = (len-2)/2;i>=0;i--) heapify(arr,len,i);

#if DEBUG & DEBUG_HEAPSORT
    sortPrint(arr,len);
#endif

}



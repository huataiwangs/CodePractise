//
// Created by songwang on 6/9/2023.
//
#include <stdio.h>
#include "Common.h"
#include "MergeSort.h"


/**
 * @brief : merge Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : best time ,worst time ,average time : nlog2n ; space: n; Stability;
 * always used for objects
 * */
void mergeSort(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    mergeSortSubArray(arr,len,0,len-1);

}

/**
 * @brief : mergeSort of SubArray
 * @param arr : Input array
 * @param len : Array length
 * @param left : left ptr of array
 * @param right : right ptr of array
 * @return : NULL
 * */
void mergeSortSubArray(int* arr,int len,int left,int right)
{
    /* Security check */
    if(arr == NULL || len<2 || left>=right) return;

    int mid = left + (right-left)/2;

    mergeSortSubArray(arr,len,left,mid);

    mergeSortSubArray(arr,len,mid+1,right);

    mergeArray(arr,len,left,mid+1,right);

}

/**
 * @brief : merge Array
 * @param arr : Input array
 * @param len : Array length
 * @param left : left ptr of 1st array
 * @param right : left ptr of 2nd array
 * @param rightBoundary : right ptr of 2nd array
 * @return : NULL
 * */
void mergeArray(int* arr,int len,int left,int right,int rightBoundary)
{
    /* Security check */
    if(arr == NULL || len<2 || left>right || rightBoundary<right || rightBoundary>=len) return;

    int leftBoundary = right-1;
    int mergeLen = rightBoundary - left + 1;
    int mergeArr[mergeLen];
    int ptr = 0;
    int l = left;

    while(left<=leftBoundary && right<=rightBoundary) mergeArr[ptr++] = arr[left]<arr[right]?arr[left++]:arr[right++];

    while(right<=rightBoundary) mergeArr[ptr++] = arr[right++];
    while(left<=leftBoundary) mergeArr[ptr++] = arr[left++];

#if DEBUG & DEBUG_MERGESORT

    printf("Merge Array :");
    sortPrint(mergeArr,mergeLen);

#endif

    for(int i = 0;i<mergeLen; i++)  arr[l+i] = mergeArr[i];

#if DEBUG & DEBUG_MERGESORT

    printf("Array after merge from %d to %d :",l+1,rightBoundary);
    sortPrint(arr,len);

#endif

}
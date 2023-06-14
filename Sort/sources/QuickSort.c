//
// Created by songwang on 6/9/2023.
//

#include "stdio.h"
#include <stdlib.h>
#include <time.h>

#include "Common.h"
#include "QuickSort.h"

/**
 * @brief : quick Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void quickSort(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    /* optimize */
    srand(time(0));
    sortSwap(arr,len,rand()%len,len-1);

    singleAxisSort(arr,len,0,len-1);
}

/**
 * @brief : single Axis Sort
 * @param arr : Input array
 * @param len : Array length
 * @param left : left ptr of array
 * @param right : right ptr of array
 * @return : NULL
 * @attention : best time ,average time : nlog2n , worst time n^2 ; space: log2n; Instability;
 *  always used for array
 * */
void singleAxisSort(int* arr,int len,int left,int right)
{
    /* boundary check */
    if(left >=right) return;

    int mid = singleAxisSubSort(arr,len,left,right);

    singleAxisSort( arr,len,left,mid-1);
    singleAxisSort( arr,len,mid+1,right);


}
/**
 * @brief : single Axis SubSort
 * @param arr : Input array
 * @param len : Array length
 * @param left : left ptr of array
 * @param right : right ptr of array
 * @return : NULL
 * */
int singleAxisSubSort(int* arr,int len,int left,int right)
{
    /* boundary check */
    if(left == right) return left;

    int l = left;
    int r = right-1;

    while(l<=r)
    {
        while(l<=r && arr[l]<=arr[right]) l++;
        while(l<=r && arr[r]>arr[right]) r--;

        if(l<r) sortSwap(arr,len,l,r);
    }

    sortSwap(arr,len,l,right);

    return l;

}

/* doubleAxisSort */
//
// Created by songwang on 6/9/2023.
//

#include "stdio.h"
#include "ShellSort.h"
#include "Common.h"

/**
 * @brief : Shell Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * @attention : worst time n^2 ,average time : n^1.3  ; best time n ; space: 1  ; Instability;
 * */
void shellSort(int* arr,int len)
{
//    shellSortShell(arr,len);
    shellSortKnuth(arr,len);

}

/**
 * @brief : Shell Sort; gap = len/2;
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void shellSortShell(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    /* gap >>=1  ==  gap/=2 */
    for (int gap = len>>1; gap>0; gap>>=1)
    {
       for(int i = gap;i<len;i++)
       {
           for(int j = i;j>gap-1 && arr[j]<arr[j-gap];j-=gap)
           {
               sortSwap(arr,len,j,j-gap);
           }
       }

    }
}

/**
 * @brief : Shell Sort; h = 1; h = 3*h+1;
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void shellSortKnuth(int* arr,int len)
{
    /* Security check */
    if(arr == NULL || len<2) return;

    /* find gap  */
    int h = 1;
    while(h<=len/3) h = h*3+1;

    for (int gap = h; gap>0; gap = (gap-1)/3)
    {
        for(int i = gap;i<len;i++)
        {
            for(int j = i;j>gap-1 && arr[j]<arr[j-gap];j-=gap)
            {
                sortSwap(arr,len,j,j-gap);
            }
        }

    }

}
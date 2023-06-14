//
// Created by songwang on 6/9/2023.
//

#include "stdio.h"
#include "string.h"
#include "math.h"
#include "RadixSort.h"
#include "Common.h"


/**
 * @brief : radix Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void radixSort(int* arr,int len)
{
    radixSortByNumRange0to99(arr,len);
}

/**
 * @brief : radix Sort By number and array range from 0 to 99
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void radixSortByNumRange0to99(int* arr,int len)
{
    radixSortByNum(arr,len,0,99);
}

/**
 * @brief : radix Sort By number
 * @param arr : Input array
 * @param len : Array length
 * @param min : min num of array
 * @param max : max num of array
 * @return : NULL
 * @attention : radix based number, so,bucket range from 0 to 9
 * best time ,worst time ,average time : n*k ; space: n+k ; Stability;
 * */
void radixSortByNum(int* arr,int len,int min,int max)
{
    /* Security check */
    if(arr == NULL || len <2 || min>=max) return;

    /* num of keywords */
    int num = 0;
    int number = max - min;
    while(number != 0)
    {
        number /= 10;
        num++;
    }

    /* range of bucket from 0 to 9 */
    int start = 0;
    int end = 9;

    /* init 0 */
    int bucketArr[end-start+1];

    /* copy array */
    int originArr[len];
    memcpy(originArr,arr,sizeof(originArr));


    for(int n = 0;n<num;n++)
    {
        int div = pow(10,n);

        memset(bucketArr,0, sizeof(bucketArr));

        // push buscket
        for(int i = 0;i<len;i++) bucketArr[(arr[i]-start)/div%10]++;

        // Construct a cumulative array
        for(int i= 0; i<(end-start+1)-1; i++) bucketArr[i+1] += bucketArr[i];

#if DEBUG & DEBUG_RADIXSORT
        printf("cumulative bucket Array :");
        sortPrint(bucketArr,end-start+1);
#endif

        for(int i = len-1;i>=0;i--) arr[--bucketArr[(originArr[i]-start)/div%10]] = originArr[i];

        memcpy(originArr,arr,sizeof(originArr));

#if DEBUG & DEBUG_RADIXSORT
        printf("After radix sort :");
        sortPrint(arr,len);
#endif

    }

}
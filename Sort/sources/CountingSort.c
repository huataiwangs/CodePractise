//
// Created by songwang on 6/9/2023.
//
#include "stdio.h"
#include <string.h>
#include "Common.h"
#include "CountingSort.h"

/**
 * @brief : Counting Sort
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void countingSort(int* arr,int len)
{
    countingSortByRange0to9(arr,len);
}

/**
 * @brief : countingSort with range from 0 to 9
 * @param arr : Input array
 * @param len : Array length
 * @return : NULL
 * */
void countingSortByRange0to9(int* arr,int len)
{
    countingSortByRange2(arr,len,0,9);
//    countingSortByRange(arr,len,0,9);
}

/**
 * @brief : countingSort with range
 * @param arr : Input array
 * @param len : Array length
 * @param start : start of range
 * @param end : end of range
 * @return : NULL
 * @attention : best time ,worst time ,average time : n+k ; space: k ; instability;
 * */
void countingSortByRange(int* arr,int len,int start,int end)
{
    /* Security check */
    if(arr == NULL || len <1 || start>end) return;

    /* init 0 */
    int bucketArr[end-start+1];
    memset(bucketArr,0, sizeof(bucketArr));

    // push buscket
    for(int i = 0;i<len;i++) bucketArr[arr[i]-start]++;

#if DEBUG & DEBUG_COUNTINGSORT
    printf("bucket Array :");
    sortPrint(bucketArr,end-start+1);
#endif

    int count = 0;
    for(int i= 0; i<(end-start+1); i++) while(bucketArr[i]-->0) arr[count++] = i+start;

#if DEBUG & DEBUG_COUNTINGSORT
    printf("After counting sort :");
    sortPrint(arr,len);
#endif


}

/**
 * @brief : countingSort with range; After optimization
 * @param arr : Input array
 * @param len : Array length
 * @param start : start of range
 * @param end : end of range
 * @return : NULL
 * @attention : best time ,worst time ,average time : n+k ; space: k ; Stability;
 * */
void countingSortByRange2(int* arr,int len,int start,int end)
{
    /* Security check */
    if(arr == NULL || len <2 || start>=end) return;

    /* init 0 */
    int bucketArr[end-start+1];
    memset(bucketArr,0, sizeof(bucketArr));

    /* copy array */
    int originArr[len];
    memcpy(originArr,arr,sizeof(originArr));

    // push buscket
    for(int i = 0;i<len;i++) bucketArr[arr[i]-start]++;

    // Construct a cumulative array
    for(int i= 0; i<(end-start+1)-1; i++) bucketArr[i+1] += bucketArr[i];

#if DEBUG & DEBUG_COUNTINGSORT
    printf("cumulative bucket Array :");
    sortPrint(bucketArr,end-start+1);
#endif

    for(int i = len-1;i>=0;i--) arr[--bucketArr[originArr[i]-start]] = originArr[i];

#if DEBUG & DEBUG_COUNTINGSORT
    printf("After counting sort :");
    sortPrint(arr,len);
#endif


}



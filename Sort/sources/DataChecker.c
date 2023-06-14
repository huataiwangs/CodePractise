//
// Created by songwang on 6/9/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "DataChecker.h"
#include "Common.h"
#include "RandomArray.h"

int cmp(const void* pa,const void* pb)
{
    /* ascending order */
    return *(int*)pa - *(int*)pb;
    /* descending order */
//    return *(int*)pb - *(int*)pa;
}

/**
 * @brief : quick sort for int array ues clib to ascending order
 * @param originArray : Input origin array
 * @param originLen : origin length
 * @return : NULL
 * */
void qsort_int_u(int* originArray,int originLen)
{
    qsort(originArray,originLen,sizeof(originArray[0]),cmp); // 传入函数指针
}

/**
 * @brief : Check data
 * @param orderedArray : Input ordered array
 * @param orderedLen : Array length
 * @param originArray : Input origin array
 * @param originLen : origin length
 * @param sort : function pointer
 * @return : true 0，false 1
 * */
int dataCheck(int* orderedArray,int orderedLen,int* originArray,int originLen,void (*sort)(int* ,int))
{
    /* Security check */
    if(orderedLen != originLen || orderedArray == NULL ||originArray== NULL)
    {
        printf("[Error][dataCheck] param error! \n");
        return 1;
    }

    /* 使用 clib 里的 quick sort 做  baseline */
    (*sort)(originArray, originLen);

#if DEBUG & DEBUG_DATACHECKER

    printf("[DataCheck] : \n");
    /* print originArray and  orderedArray */
    printf("orderedArray = ");
    sortPrint(orderedArray, orderedLen);
    printf("originArray  = ");
    sortPrint(originArray, originLen);

#endif

    for(int i = 0;i< originLen;i++)
    {
        if(originArray[i] != orderedArray[i])
        {

#if DEBUG & DEBUG_DATACHECKER
            printf("[Warning][dataCheck] orderedArray cant match originArray ! \n");
#endif

            return 1;
        }
    }

#if DEBUG & DEBUG_DATACHECKER
            printf("[Success][dataCheck] orderedArray match originArray successfully! \n");
#endif

    return 0;

}

/**
 * @brief : Check data use qsort
 * @param orderedArray : Input ordered array
 * @param orderedLen : ordered length
 * @param originArray : Input origin array
 * @param originLen : origin length
 * @return : true 0，false 1
 * */
int dataCheck_qsort(int* orderedArray,int orderedLen,int* originArray,int originLen)
{
    return dataCheck(orderedArray,orderedLen,originArray,originLen,qsort_int_u);
}

/**
 * @brief : Check sort function
 * @param sort : Input sort function pointer
 * @param ArrayGenerator : Input ArrayGenerator function pointer
 * @param dataCheck : Input dataCheck function pointer
 * @param len : Array length
 * @param freq : number of times of test
 * @return : true 0，false 1
 * */
int sortCheck(void (*sort)(int* ,int),void (*ArrayGenerator)(int* ,int),int (*dataCheck)(int* ,int ,int* ,int ),int len,int freq)
{
    int src[len];
    int dst[len];
    int ret;
    ret = 0;

    while(freq-->0)
    {
        (*ArrayGenerator)(src,len);
        memcpy(dst,src,sizeof(src));

#if DEBUG & DEBUG_DATACHECKER
        /* After memcpy */
        printf("After memcpy dst array data:");
        sortPrint(dst, len);
#endif

        /* sort */
        (*sort)(src ,len);

#if DEBUG & DEBUG_DATACHECKER
        /* After sort */
        printf("After sort src array data:");
        sortPrint(src, len);
#endif

        ret = (((*dataCheck)(src,len,dst,len) || ret) == 1)?1:0;
    }

    return ret;

}

/**
 * @brief : Check sort function
 * @param sort : Input sort function pointer
 * @param ArrayGenerator : Input ArrayGenerator function pointer
 * @param len : Array length
 * @param freq : number of times of test
 * @return : true 0，false 1
 * */
int sortCheckByQSort(void (*sort)(int* ,int),void (*ArrayGenerator)(int* ,int),int len,int freq)
{
    /* data check use qsort*/
    return sortCheck(sort,ArrayGenerator,dataCheck_qsort,len,freq);
}

/**
 * @brief : Check sort function
 * @param sort : Input sort function pointer
 * @return : true 0，false 1
 * */
int sortCheckByQSort_0to9_10_5(void (*sort)(int* ,int))
{
    return sortCheckByQSort(sort,randomArrayRange0to9,10, 5);
}


/**
 * @brief : Check sort function
 * @param sort : Input sort function pointer
 * @return : true 0，false 1
 * */
int sortCheckByQSort_0to99_10_5(void (*sort)(int* ,int))
{
    return sortCheckByQSort(sort,randomArrayRange0to99,10, 5);
}

/**
 * @brief : Check sort function
 * @param sort : Input sort function pointer
 * @return : NULL
 * */
void dataChecker(void (*sort)(int* ,int))
{
//    if(sortCheckByQSort_0to9_10_5(sort))
    if(sortCheckByQSort_0to99_10_5(sort))
    {
        printf("[Error][DataChecker] error!!! \n");
    }
    else
    {
        printf("[Success][DataChecker] success!!! \n");
    }

}

/**
 * @brief : Check sort function; test case from 0 to 9
 * @param sort : Input sort function pointer
 * @return : NULL
 * */
void dataCheckerRange0to9(void (*sort)(int* ,int))
{
//    if(sortCheckByQSort_0to99_10_5(sort))
    if(sortCheckByQSort_0to9_10_5(sort))
    {
        printf("[Error][DataChecker] error!!! \n");
    }
    else
    {
        printf("[Success][DataChecker] success!!! \n");
    }

}
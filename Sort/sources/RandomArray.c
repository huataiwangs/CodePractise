//
// Created by songwang on 6/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include "Common.h"
#include "RandomArray.h"

/**
 * @brief : Generate a random array with a length of len and range from start to end
 * @param randomArray : Input array addr
 * @param len : Array length
 * @param start : start of range
 * @param end : end of range
 * @return : NULL
 * */
void randomArrayGenerator(int* randomArray,int len,int start,int end)
{
    /* Security check */
    if(randomArray == NULL || len <=0 || end < start)
    {
        printf("[Error][randomArrayGenerator] Input arguments error \n");
        return;
    }

    for(int i = 0; i < len;i++) randomArray[i] = start + rand()%(end - start + 1);

#if DEBUG & DEBUG_RANDOMARRAY

    printf("[Generate random array]: ");
    sortPrint(randomArray, len);

#endif

}

/**
 * @brief : Generate a random array with a length of len and range from 0 to 9
 * @param randomArray : Input array addr
 * @param len : Array length
 * @return : NULL
 * */
void randomArrayRange0to9(int* randomArray,int len)
{
    randomArrayGenerator(randomArray,len,0,9);
}

/**
 * @brief : Generate a random array with a length of len and range from 0 to 99
 * @param randomArray : Input array addr
 * @param len : Array length
 * @return : NULL
 * */
void randomArrayRange0to99(int* randomArray,int len)
{
    randomArrayGenerator(randomArray,len,0,99);
}
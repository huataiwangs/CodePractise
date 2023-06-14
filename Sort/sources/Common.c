//
// Created by songwang on 6/9/2023.
//

#include <stdio.h>
#include "Common.h"

/**
 * @brief : Print the array content in sequence
 * @param array : Input array
 * @param len : Array length
 * @return : NULL
 * */
void sortPrint(int* array, int len)
{
    /* Security check */
    if(len < 1)
    {
        printf("[Error] [sortPrint] len must above 0 \n");
        return;
    }

    for(int i = 0; i<len; i++) printf("%d ",array[i]);

    printf("\n");

}

/**
 * @brief : Swap arguments 1 and 2
 * @param array : Input array
 * @param len : Array length
 * @param i : arguments 1
 * @param j : arguments 2
 * @return : NULL
 * */
void sortSwap(int* array, int len, int i ,int j)
{
    /* Security check */
    if(len<1 || i<0 || i>=len || j<0 || j>=len)
    {
        printf("[Error] [sortSwap] arguments error \n");
        return;
    }

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

}
//
// Created by songwang on 6/10/2023.
//

#ifndef SORT_PRACTISE_DATACHECKER_H
#define SORT_PRACTISE_DATACHECKER_H

void dataChecker(void (*sort)(int* ,int));
void dataCheckerRange0to9(void (*sort)(int* ,int));

int sortCheckByQSort(void (*sort)(int* ,int),void (*ArrayGenerator)(int* ,int),int len,int freq);
int sortCheck(void (*sort)(int* ,int),void (*ArrayGenerator)(int* ,int),int (*dataCheck)(int* ,int ,int* ,int ),int len,int freq);

int dataCheck_qsort(int* orderedArray,int orderedLen,int* originArray,int originLen);
int dataCheck(int* orderedArray,int orderedLen,int* originArray,int originLen,void (*sort)(int* ,int));

void qsort_int_u(int* originArray,int originLen);

#endif //SORT_PRACTISE_DATACHECKER_H

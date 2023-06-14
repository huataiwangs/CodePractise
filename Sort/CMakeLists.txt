cmake_minimum_required(VERSION 3.10)
project(SortPractise C)

set(CMAKE_C_STANDARD 11)
set(SRCPATH ./sources)

include_directories(
        headers/
        )

add_library(sort SHARED
        ${SRCPATH}/BubbleSort.c
        ${SRCPATH}/CountingSort.c
        ${SRCPATH}/HeapSort.c
        ${SRCPATH}/InsertionSort.c
        ${SRCPATH}/MergeSort.c
        ${SRCPATH}/QuickSort.c
        ${SRCPATH}/RadixSort.c
        ${SRCPATH}/SelectionSort.c
        ${SRCPATH}/ShellSort.c
        ${SRCPATH}/Common.c
        ${SRCPATH}/RandomArray.c
        ${SRCPATH}/DataChecker.c
        )


link_libraries(sort)

add_executable(main
        main.c
        )



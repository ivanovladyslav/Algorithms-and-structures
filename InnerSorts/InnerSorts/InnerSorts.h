//
//  Merge.h
//  InnerSorts
//
//  Created by user on 30/01/2018.
//  Copyright © 2018 user. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;

#ifndef Merge_h
#define Merge_h

class InnerSorts {
    int *array_;
    int *arrayTemp_; //temporary array for inner calculations
    int *ptrarray_; //pointer for saving pointer to input array
    int size_;
public:
    InnerSorts(int*, int size);
    void mergeSortCommon(int begin, int end);
    void mergeSortRecurrent(int begin, int end);
    void shellSort();
    void heapSort();
    void quickSort(int left, int right);
    void outputArray();
    void checkCorrectness();
private:
    void merge(int begin, int end, int middle);
    void copy(int, int);
    void swap(int, int);
    void screening(int i, int m);
    void returnArray();
    int min(int, int);
};
#endif /* Merge_h */

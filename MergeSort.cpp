//
//  main.cpp
//  MergeSort
//
//  Created by user on 06/03/2018.
//  Copyright © 2018 Ivanov Vladislav. All rights reserved.
//

#include <iostream>
const int N = 10000;

int array[N];
int arrayTemp[N];

void merge(int begin, int end, int middle) {
    int counterLeft = begin;
    int counterRight = middle+1;
    for (int i = begin; i <= end; i++) {
        if (counterLeft <= middle && counterRight <= end) {
            if (array[counterLeft] >= array[counterRight]) {
                arrayTemp[i] = array[counterRight];
                counterRight++;
            } else {
                arrayTemp[i] = array[counterLeft];
                counterLeft++;
            }
        } else if (counterLeft <= middle) {
            arrayTemp[i] = array[counterLeft];
            counterLeft++;
        } else {
            arrayTemp[i] = array[counterRight];
            counterRight++;
        }
    }
}

void mergeSort(int begin, int end) {
    int middle = (begin + end) / 2;
    if (middle > begin) mergeSortCommon(begin, middle);
    if (middle + 1 < end) mergeSortCommon(middle + 1, end);
    merge(begin, end, middle);
    for (int i = begin; i <= end; i++)
        array[i] = arrayTemp[i];
}

int main() {
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;
    
    mergeSort(0,N);
    
    for (int i = 0; i < N; i++)
        std::cout << array[i] << " ";
}

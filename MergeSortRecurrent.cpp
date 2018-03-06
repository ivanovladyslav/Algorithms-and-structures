//
//  main.cpp
//  MergeSortRecurrent
//
//  Created by user on 06/03/2018.
//  Copyright © 2018 Ivanov Vladislav. All rights reserved.
//

#include <iostream>

const int N = 1000;
int array[N];
int arrayTemp[N];

int min(int first, int second) {
    if (first <= second)
        return first;
    else
        return second;
}

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

void mergeSortRecurrent(int begin, int end) {
    for (int s = 1; s <= end-begin; s *= 2) {
        for (int b = begin; b <= end-begin; b += s*2) {
            merge(b, min(b+2*s-1, end) ,b+s-1);
        }
        for (int i = begin; i <= end; i++)
            array[i] = arrayTemp[i];
    }
}

int main() {
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;
    
    mergeSortRecurrent(0, N-1);
    
    for (int i = 0; i < N; i++)
        std::cout << array[i] << " ";
}

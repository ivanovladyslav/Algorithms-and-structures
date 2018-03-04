//
//  Merge.cpp
//  InnerSorts
//
//  Created by user on 30/01/2018.
//  Copyright © 2018 user. All rights reserved.
//
#include "InnerSorts.h"

InnerSorts::InnerSorts(int *array, int size): size_(size), array_(new int[size]),
arrayTemp_(new int[size]) {
    for (int i = 0; i < size_; i++) array_[i] = array[i];
    ptrarray_ = array;
}

void InnerSorts::merge(int begin, int end, int middle) {
    int counterLeft = begin;
    int counterRight = middle+1;
    for (int i = begin; i <= end; i++) {
        if (counterLeft <= middle && counterRight <= end) {
            if (array_[counterLeft] >= array_[counterRight]) {
                arrayTemp_[i] = array_[counterRight];
                counterRight++;
            } else {
                arrayTemp_[i] = array_[counterLeft];
                counterLeft++;
            }
        } else if (counterLeft <= middle) {
            arrayTemp_[i] = array_[counterLeft];
            counterLeft++;
        } else {
            arrayTemp_[i] = array_[counterRight];
            counterRight++;
        }
    }
}

void InnerSorts::copy(int begin, int end) {
    for (int i = begin; i <= end; i++) {
        array_[i] = arrayTemp_[i];
    }
}
void InnerSorts::swap(int left, int right) {
    int temp = array_[left];
    array_[left] = array_[right];
    array_[right] = temp;
}

void InnerSorts::returnArray() {
    for (int i = 0; i < size_; i++) 
        ptrarray_[i] = array_[i];
}

void InnerSorts::checkCorrectness() {
    for (int i = 0; i < size_ - 1; i++) {
        if (array_[i] > array_[i + 1]) {
            cout << "Array sorted wrong! \n";
            break;
        }
    }
    cout << "Array sorted correctly! \n";
}

int InnerSorts::min(int first, int second) {
    if (first <= second)
        return first;
    else
        return second;
}

void InnerSorts::mergeSortCommon(int begin, int end) {
    int middle = (begin + end) / 2;
    if (middle > begin) mergeSortCommon(begin, middle);
    if (middle + 1 < end) mergeSortCommon(middle + 1, end);
    merge(begin, end, middle);
    copy(begin, end);
}

void InnerSorts::mergeSortRecurrent(int begin, int end) {
    for (int s = 1; s <= end-begin; s *= 2) {
        for (int b = begin; b <= end-begin; b += s*2) {
            merge(b, min(b+2*s-1, end) ,b+s-1);
        }
        copy(0, end);
    }
    returnArray();
}

void InnerSorts::shellSort() {
    int h;
    for (h = 1; h <= size_; h = 3 * h + 1); // finding beginning distance between elements
    while (h >= 1) {
        for (int i = h; i < size_; i++) {
            /*while j element bigger than j+h element decreasing j and swapping elements*/
            for (int j = i - h; j >= 0 && array_[j] > array_[j+h]; j -= h) {
                swap(j, j+h);
            }
        }
        h = (h - 1) / 3; //decreasing distance between elements
    }
    returnArray();
}

void InnerSorts::screening(int i, int m) {
    int j = i,
    k = j * 2 + 1;
    //while root having child
    while (k <= m) {
        // choosing bigger child
        if (k < m && array_[k] < array_[k+1]) k++;
        //transfering element to top
        if (array_[j] < array_[k]) {
            swap(j, k);
            j = k;
            k = k * 2 + 1;
        }
        else break;
    }
}

void InnerSorts::heapSort() {
    //creating heap
    for (int i = size_ / 2; i >= 0; i--) screening(i, size_-1);
    for (int m = size_ - 1; m >= 1; m--) {
        //swapping first element and last element
        swap(0, m);
        //restoring heap
        screening(0, m-1);
    }
    returnArray();
}

void InnerSorts::quickSort(int left, int right) {
    int borderLeft = left,
        borderRight = right;
    while (borderLeft < borderRight) {
        int x = array_[(borderLeft + borderRight) / 2];
        int i = borderLeft,
            j = borderRight;
        while (i < j) {
            while (array_[i] < x) i++;
            while (array_[j] > x) j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        //choosing next field to sort
        if (j - borderLeft < borderRight - i) {
            if (borderLeft < j) quickSort(borderLeft, j);
            borderLeft = i;
        } else {
            if (i < borderRight) quickSort(i, borderRight);
            borderRight = j;
        }
    }
    if (borderLeft == borderRight) returnArray();
}


void InnerSorts::outputArray() {
    if (size_ <= 10) {
        cout << "Output array: \n";
        for (int i = 0; i < size_; i++) {
            cout << array_[i] << " ";
        }
        cout << endl;
    } else cout << "No output because of big array length \n";
}

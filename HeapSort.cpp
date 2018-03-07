//
//  main.cpp
//  HeapSort
//
//  Created by user on 07/03/2018.
//  Copyright © 2018 Ivanov Vladislav. All rights reserved.
//

#include <iostream>

const int N = 1000;

int array[N];

void screening(int i, int m) {
    int j = i,
    k = j * 2 + 1;
    //while root having child
    while (k <= m) {
        // choosing bigger child
        if (k < m && array[k] < array[k+1]) k++;
        //transfering element to top
        if (array[j] < array[k]) {
            int temp = array[j];
            array[j] = array[k];
            array[k] = temp;
            j = k;
            k = k * 2 + 1;
        }
        else break;
    }
}

void heapSort() {
    //creating heap
    for (int i = N / 2; i >= 0; i--) screening(i, N-1);
    for (int m = N - 1; m >= 1; m--) {
        //swapping first element and last element
        int temp = array[0];
        array[0] = array[m];
        array[m] = temp;
        //restoring heap
        screening(0, m-1);
    }
}

int main() {
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;
    
    heapSort();
    
    for (int i = 0; i < N; i++)
        std::cout << array[i] << " ";
}

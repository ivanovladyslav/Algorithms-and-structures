//
//  main.cpp
//  InnerSorts
//
//  Created by user on 29/01/2018.
//  Copyright © 2018 user. All rights reserved.
//

#include "InnerSorts.h"

int* arrayGenerate(int size) {
    int *arr = new int[size];
    int type;
    cout << "1 - Generate random array \n";
    cout << "2 - Generate array sorted in ascending order \n";
    cout << "3 - Generate array sorted in descending order \n";
    cin >> type;
    cout << "Source array: \n";
    switch(type) {
        case 1: {
            for (int i = 0; i < size; i++)
                arr[i] = rand() % 100;
            break;
        }
        case 2: {
            arr[0] = rand() % 10;
            for (int i = 1; i < size; i++)
                arr[i] = arr[i-1] + (rand() % 10);
            break;
        }
        case 3: {
            arr[size-1] = rand() % 10;
            for (int i = size-2; i >= 0; i--)
                arr[i] = arr[i+1] + (rand() % 10);
            break;
        }
    }
    if (size <= 10) {
        for (int i = 0; i < size; i++ )
            cout << arr[i] << " ";
        cout << endl;
    }
    return arr;
}

int main() {
    int size;
    clock_t time;
    cout << fixed;
    cout << setprecision(6);
    cout << "Input size of array: \n";
    cin >> size;
    int *arr;
    
    //Merge sorting
    cout << "Merge sort. \n";
    arr = arrayGenerate(size);
    InnerSorts sort1(arr, size);
    time = clock();
    sort1.mergeSortRecurrent(0, size - 1);
    time = clock() - time;
    sort1.outputArray();
    sort1.checkCorrectness();
    cout << "Sort execution time: " << (double)time/CLOCKS_PER_SEC << endl << endl;
    
    //Shell sorting
    cout << "Shell sort. \n";
    arr = arrayGenerate(size);
    InnerSorts sort2(arr, size);
    time = clock();
    sort2.shellSort();
    time = clock() - time;
    sort2.outputArray();
    sort2.checkCorrectness();
    cout << "Sort execution time: " << (double)time/CLOCKS_PER_SEC << endl << endl;
    
    //Pyramid sorting
    cout << "Pyramid sort. \n";
    arr = arrayGenerate(size);
    InnerSorts sort3(arr, size);
    time = clock();
    sort3.heapSort();
    time = clock() - time;
    sort3.outputArray();
    sort3.checkCorrectness();
    cout << "Sort execution time: " << (double)time/CLOCKS_PER_SEC << endl << endl;
    
    //Quick sorting
    cout << "Quick sort. \n";
    arr = arrayGenerate(size);
    InnerSorts sort4(arr, size);
    time = clock();
    sort4.quickSort(0, size-1);
    time = clock() - time;
    sort4.outputArray();
    sort4.checkCorrectness();
    cout << "Sort execution time: " << (double)time/CLOCKS_PER_SEC << endl << endl;
    
//  You can also display array like this:
//    for (int i = 0; i < size; i++ ) {
//        cout << arr[i] << " ";
//    }
}

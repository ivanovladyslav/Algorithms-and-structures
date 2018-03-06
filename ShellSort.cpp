//
//  main.cpp
//  ShellSort
//
//  Created by user on 06/03/2018.
//  Copyright © 2018 Ivanov Vladislav. All rights reserved.
//

#include <iostream>

const int N = 1000;

int array[N];
int arrayTemp[N];

void shellSort() {
    int h;
    for (h = 1; h <= N; h = 3 * h + 1); // finding beginning distance between elements
    while (h >= 1) {
        for (int i = h; i < N; i++) {
            /*while j element bigger than j+h element decreasing j and swapping elements*/
            for (int j = i - h; j >= 0 && array[j] > array[j+h]; j -= h) {
                int temp = array[j];
                array[j] = array[j+h];
                array[j+h] = temp;
            }
        }
        h = (h - 1) / 3; //decreasing distance between elements
    }
}

int main() {
    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;
    
    shellSort();
    
    for(int i = 0; i < N; i++)
        std::cout << array[i] << " ";
}

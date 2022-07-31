#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <cmath>
#include "Sort.h"

using namespace std;

const int arrSize = 50;
const int maxHeight = 25;

int main()
{
    srand(time(0));

    int numsArr[arrSize];
    int length = sizeof(numsArr) / sizeof(numsArr[0]);
    int start = 0;
    int end = length - 1;

    generateRandomArray(numsArr, arrSize, maxHeight);
    printGraph(numsArr, arrSize, maxHeight);
    displayArray(numsArr, arrSize);

    bubbleSort(numsArr, arrSize);
    printGraph(numsArr, arrSize, maxHeight);

    generateRandomArray(numsArr, arrSize, maxHeight);
    printGraph(numsArr, arrSize, maxHeight);
    displayArray(numsArr, arrSize);

    selectionSort(numsArr, arrSize);
    printGraph(numsArr, arrSize, maxHeight);

    generateRandomArray(numsArr, arrSize, maxHeight);
    printGraph(numsArr, arrSize, maxHeight);
    displayArray(numsArr, arrSize);

    mergeSort(numsArr, start, end);
    printGraph(numsArr, arrSize, maxHeight);

    generateRandomArray(numsArr, arrSize, maxHeight);
    printGraph(numsArr, arrSize, maxHeight);
    displayArray(numsArr, arrSize);

    quickSort(numsArr, start, end);
    printGraph(numsArr, arrSize, maxHeight);

    return 0;
}

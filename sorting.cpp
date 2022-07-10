#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <cmath>

using namespace std;

void generateRandomArray(int numsArr[], const int arrSize, const int maxHeight)
{
    for (int i = 0; i < arrSize; i++)
    {
        numsArr[i] = (rand() % maxHeight) + 1;
    }
}

void printGraph(int numsArr[], const int arrSize, const int maxHeight)
{
    cout << endl;
    for (int i = maxHeight; i > 0; i--)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if (numsArr[j] >= i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < arrSize; i++)
        cout << "--";
    cout << endl
         << endl;
}

int highestNumber(int numsArr[], const int arrSize)
{
    int highestNum = numsArr[0];

    for (int i = 1; i < arrSize; i++)
    {
        if (highestNum < numsArr[i])
            highestNum = numsArr[i];
    }
    return highestNum;
}

int indexOfMin(int numsArr[], const int arrSize, int start)
{
    int minIndex = start;

    for (int i = start + 1; i < arrSize; i++)
    {
        if (numsArr[i] < numsArr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void bubbleSort(int numsArr[], const int arrSize)
{
    bool swap;
    int temp;
    int count = 0;

    do
    {
        swap = false;
        for (int i = 0; i < arrSize; i++)
        {
            if (numsArr[i] > numsArr[i + 1])
            {
                temp = numsArr[i];
                numsArr[i] = numsArr[i + 1];
                numsArr[i + 1] = temp;
                swap = true;
            }
        }
        count++;
    } while (swap);

    cout << "Number of Bubble Sort comparisons: " << count << endl;
}

void selectionSort(int numsArr[], const int arrSize)
{
    int temp;
    int minIndex;
    int count = 0;
    for (int i = 0; i < (arrSize - 1); i++)
    {
        minIndex = indexOfMin(numsArr, arrSize, i);
        temp = numsArr[minIndex];
        numsArr[minIndex] = numsArr[i];
        numsArr[i] = temp;
        count++;
    }
    cout << "Number of Selection Sort comparisons: " << count << endl;
}

const int arrSize = 50;
const int maxHeight = 25;

int main()
{
    srand(time(0));

    int numsArr[arrSize];

    generateRandomArray(numsArr, arrSize, maxHeight);

    printGraph(numsArr, arrSize, maxHeight);

    /*for (int i = 0; i < arrSize; i++)
    {
        cout << numsArr[i] << " ";
    } */

    bubbleSort(numsArr, arrSize);
    printGraph(numsArr, arrSize, maxHeight);
    generateRandomArray(numsArr, arrSize, maxHeight);
    printGraph(numsArr, arrSize, maxHeight);
    selectionSort(numsArr, arrSize);
    printGraph(numsArr, arrSize, maxHeight);

    return 0;
}

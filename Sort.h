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

void displayArray(int numsArr[], const int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << numsArr[i] << " ";
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
}

void merge(int *array, int start, int end, int mid)
{
    int i, j, k;
    int *temp = new int[end - start + 1];
    i = start;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        temp[k] = array[j];
        k++;
        j++;
    }

    for (i = start; i <= end; i++)
    {
        array[i] = temp[i - start];
    }
}

void mergeSort(int *array, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, end, mid);
    }
    return;
}

int partition(int numsArr[], int start, int end)
{

    int pivot = numsArr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (numsArr[j] < pivot)
        {
            i++;
            int temp = numsArr[i];
            numsArr[i] = numsArr[j];
            numsArr[j] = temp;
        }
    }
    i++;
    int temp = numsArr[i];
    numsArr[i] = numsArr[end];
    numsArr[end] = temp;

    return i;
}

void quickSort(int numsArr[], int start, int end)
{
    if (end <= start)
        return;

    int pivot = partition(numsArr, start, end);
    quickSort(numsArr, start, pivot - 1);
    quickSort(numsArr, pivot + 1, end);
}
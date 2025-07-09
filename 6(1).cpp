#include <iostream>
#include <windows.h>
using namespace std;

const int ARRAY_SIZE = 10;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int findMinIndex(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[minIndex])
            minIndex = i;
    return minIndex;
}

int findMaxIndex(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

void swapExtremes(int arr[], int size) {
    int minIndex = findMinIndex(arr, size);
    int maxIndex = findMaxIndex(arr, size);

    swap(arr[0], arr[minIndex]);

    if (maxIndex == 0) maxIndex = minIndex;

    swap(arr[size - 1], arr[maxIndex]);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int array[ARRAY_SIZE] = {17, 5, 23, 4, 89, 3, 12, 44, 7, 66};

    cout << "Исходный массив: ";
    printArray(array, ARRAY_SIZE);

    swapExtremes(array, ARRAY_SIZE);

    cout << "Массив после замены минимум ↔ первый и максимум ↔ последний: ";
    printArray(array, ARRAY_SIZE);

    return 0;
}

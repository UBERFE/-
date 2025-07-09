#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

void generateRandomArray(int* arr, int size, int min = 1, int max = 100) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % (max - min + 1) + min;
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void copyPrimesToNewArray(const int* source, int* dest, int size, int* newSize) {
    *newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(*(source + i))) {
            *(dest + *newSize) = *(source + i);
            (*newSize)++;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int SIZE = 20;
    int original[SIZE];
    int primes[SIZE];
    int primesCount;

    generateRandomArray(original, SIZE);
    cout << "Исходный массив:\n";
    printArray(original, SIZE);

    copyPrimesToNewArray(original, primes, SIZE, &primesCount);

    cout << "\nМассив простых чисел:\n";
    printArray(primes, primesCount);

    return 0;
}

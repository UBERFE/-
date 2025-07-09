#include <iostream>
#include <windows.h> 
using namespace std;

bool isEven(int number) {
    return number % 2 == 0;
}

void inputArray(int arr[], int& size) {
    cout << "Введите количество элементов массива: ";
    cin >> size;
    for (int i = 0; i < size; ++i) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void outputArray(const int arr[], int size) {
    cout << "Массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeEven(int arr[], int& size) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (!isEven(arr[i])) {
            arr[j++] = arr[i];
        }
    }
    size = j;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int MAX_SIZE = 100;
    int array[MAX_SIZE];
    int size;

    inputArray(array, size);

    cout << "\nВведённый массив:\n";
    outputArray(array, size);

    if (size > 0) {
        cout << "\nПервый элемент (" << array[0] << ") ";
        if (isEven(array[0]))
            cout << "является чётным.\n";
        else
            cout << "является нечётным.\n";
    }

    removeEven(array, size);

    cout << "\nМассив после удаления чётных чисел:\n";
    outputArray(array, size);

    return 0;
}

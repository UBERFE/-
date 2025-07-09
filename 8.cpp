#include <iostream>
#include <windows.h> 
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, m;
    int matrix[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];

    cout << "Введите количество строк (n): ";
    cin >> n;

    cout << "Введите количество столбцов (m): ";
    cin >> m;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        int column[MAX_ROWS];

        for (int i = 0; i < n; i++) {
            column[i] = matrix[i][j];
        }

        sortDescending(column, n);

        for (int i = 0; i < n; i++) {
            result[i][j] = column[i];
        }
    }

    cout << "\nМатрица после сортировки столбцов по убыванию:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

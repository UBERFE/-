#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double num1, num2;
    char op;

    cout << "=== Простой калькулятор ===\n";

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;
    cout << "Введите второе число: ";
    cin >> num2;

    switch (op) {
        case '+':
            cout << "Результат: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Результат: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Результат: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Результат: " << num1 / num2 << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Ошибка: неизвестная операция!" << endl;
    }

    cout << "Программа завершена.\n";
    return 0;
}

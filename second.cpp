#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char choice;

    do {
        int K1, K2, M1, M2, M3, keyboard, mouse;

        cout << "Введите цену системного блока K1 и K2: ";
        cin >> K1 >> K2;

        cout << "Введите цену монитора M1, M2, M3: ";
        cin >> M1 >> M2 >> M3;

        cout << "Введите цену клавиатуры: ";
        cin >> keyboard;

        cout << "Введите цену мыши: ";
        cin >> mouse;

        int minSystem = (K1 < K2) ? K1 : K2;
        int minMonitor = M1;
        if (M2 < minMonitor) minMonitor = M2;
        if (M3 < minMonitor) minMonitor = M3;
        int minTotal = minSystem + minMonitor + keyboard + mouse;

        int maxSystem = (K1 > K2) ? K1 : K2;
        int maxMonitor = M1;
        if (M2 > maxMonitor) maxMonitor = M2;
        if (M3 > maxMonitor) maxMonitor = M3;
        int maxTotal = maxSystem + maxMonitor + keyboard + mouse;

        cout << "\nСамый дешёвый компьютер стоит: " << minTotal << " руб." << endl;
        cout << "Самый дорогой компьютер стоит: " << maxTotal << " руб." << endl;

        cout << "\nХотите выполнить расчёт снова? (д/н): ";
        cin >> choice;

    } while (choice == 'д' || choice == 'Д');

    cout << "\nРабота программы завершена." << endl;
    return 0;
}

#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    double K1, K2, K3;
    cout << "Введите количество корма для мыши в день (г): ";
    cin >> K1;
    cout << "Введите количество корма для крысы в день (г): ";
    cin >> K2;
    cout << "Введите количество корма для морской свинки в день (г): ";
    cin >> K3;

    int X, Y, Z;
    cout << "Введите количество мышей: ";
    cin >> X;
    cout << "Введите количество крыс: ";
    cin >> Y;
    cout << "Введите количество морских свинок: ";
    cin >> Z;

    double daily_food = (K1 * X) + (K2 * Y) + (K3 * Z);

    double monthly_food = daily_food * 30;

    cout << "\nРезультаты расчетов:" << endl;
    cout << "Корм в день: " << daily_food << " г" << endl;
    cout << "Корм в месяц (30 дней): " << monthly_food << " г" << endl;

    return 0;
}

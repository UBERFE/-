#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
using namespace std;

const int MONTHS = 12;
const int TEAMS = 4;

string monthNames[MONTHS] = {
    "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
    "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
};

struct Data {
    string month;
    int work[TEAMS];
    int total;
};

void input(Data arr[]) {
    for (int i = 0; i < MONTHS; i++) {
        arr[i].month = monthNames[i];
        arr[i].total = 0;
        cout << "Месяц: " << arr[i].month << endl;
        for (int j = 0; j < TEAMS; j++) {
            cout << "  Бригада " << (j + 1) << ": ";
            cin >> arr[i].work[j];
            arr[i].total += arr[i].work[j];
        }
    }
}

void printLine(int columns) {
    cout << "+------------";
    for (int i = 0; i < columns; i++) cout << "+--------";
    cout << "+---------+" << endl;
}

void output(Data arr[]) {
    printLine(TEAMS);
    cout << "| Месяц     ";
    for (int i = 0; i < TEAMS; i++) {
        cout << "| Бр" << i + 1 << "   ";
    }
    cout << "| Итого  |" << endl;
    printLine(TEAMS);

    for (int i = 0; i < MONTHS; i++) {
        cout << "| " << setw(10) << left << arr[i].month;
        for (int j = 0; j < TEAMS; j++) {
            cout << "| " << setw(6) << arr[i].work[j];
        }
        cout << "| " << setw(7) << arr[i].total << "|" << endl;
    }

    printLine(TEAMS);
}

void avgPerTeam(Data arr[]) {
    cout << "\nСредняя выработка по бригадам:\n";
    for (int i = 0; i < TEAMS; i++) {
        int sum = 0;
        for (int j = 0; j < MONTHS; j++) {
            sum += arr[j].work[i];
        }
        cout << "Бригада " << (i + 1) << ": " << sum / MONTHS << endl;
    }
}

void findByMonth(Data arr[], string name) {
    for (int i = 0; i < MONTHS; i++) {
        if (arr[i].month == name) {
            cout << "\nВыработка за " << name << ":\n";
            for (int j = 0; j < TEAMS; j++) {
                cout << "Бригада " << (j + 1) << ": " << arr[i].work[j] << endl;
            }
            cout << "Итого: " << arr[i].total << endl;
            return;
        }
    }
    cout << "Месяц не найден.\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Data table[MONTHS];

    input(table);
    output(table);
    avgPerTeam(table);

    string searchMonth;
    cout << "\nВведите название месяца для поиска: ";
    cin >> searchMonth;
    findByMonth(table, searchMonth);

    return 0;
}

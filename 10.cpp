#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int N = 5;
    int visits[N][2] = {
        {10, 14},
        {11, 13},
        {12, 15},
        {14, 17},
        {16, 18}
    };

    const int T_START = 0;
    const int T_END = 24;
    int timeCount[24] = {0};

    for (int i = 0; i < N; i++) {
        int inTime = visits[i][0];
        int outTime = visits[i][1];

        for (int t = inTime; t < outTime; t++) {
            timeCount[t]++;
        }
    }

    int maxPeople = timeCount[0];
    int minPeople = timeCount[0];

    for (int i = 1; i < 24; i++) {
        if (timeCount[i] > maxPeople) maxPeople = timeCount[i];
        if (timeCount[i] < minPeople) minPeople = timeCount[i];
    }

    cout << "Максимум посетителей: " << maxPeople << " в промежутках: ";
    for (int i = 0; i < 24; i++) {
        if (timeCount[i] == maxPeople) {
            cout << i << ":00-" << i + 1 << ":00 ";
        }
    }

    cout << endl;

    cout << "Минимум посетителей: " << minPeople << " в промежутках: ";
    for (int i = 0; i < 24; i++) {
        if (timeCount[i] == minPeople) {
            cout << i << ":00-" << i + 1 << ":00 ";
        }
    }

    return 0;
}

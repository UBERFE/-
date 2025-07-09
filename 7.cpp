#include <iostream>
#include <windows.h>
using namespace std;

void findMax(const float* arr, int size, float* maxValue, int* maxIndex) {
    *maxValue = arr[0];
    *maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > *maxValue) {
            *maxValue = *(arr + i);
            *maxIndex = i;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int HOURS = 24;
    float temperature[HOURS] = {
        16.1, 15.8, 15.0, 14.6, 14.5, 15.2, 17.0, 19.5, 22.3, 24.8, 26.5, 28.1,
        29.3, 30.0, 29.6, 28.9, 27.4, 25.0, 22.8, 20.5, 19.2, 18.0, 17.1, 16.5
    };

    float humidity[HOURS] = {
        88.5, 90.0, 91.3, 92.4, 93.1, 90.2, 85.0, 80.5, 75.3, 70.8, 68.5, 65.1,
        60.3, 58.0, 59.6, 62.9, 66.4, 70.0, 74.8, 78.5, 81.2, 83.0, 85.1, 87.5
    };

    float maxTemp, maxHum;
    int hourTemp, hourHum;

    findMax(temperature, HOURS, &maxTemp, &hourTemp);
    findMax(humidity, HOURS, &maxHum, &hourHum);

    cout << "Максимальная температура: " << maxTemp << "°C в " << hourTemp << ":00\n";
    cout << "Максимальная влажность: " << maxHum << "% в " << hourHum << ":00\n";

    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

double Pi(double eps) {
    double product = 1.0;
    double prev_pi = 0.0;
    double current_pi = 2.0;
    int n = 1;

    while (abs(current_pi - prev_pi) > eps) {
        prev_pi = current_pi;
        double factor = (2.0 * n) / (2.0 * n - 1.0) * (2.0 * n) / (2.0 * n + 1.0);
        product *= factor;
        current_pi = 2.0 * product;
        n++;
    }

    return current_pi;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double epsilons[] = {0.01, 0.001, 0.0001};

    cout << "Вычисление числа π с заданной точностью:\n";
    cout << "Точность | Значение π\n";
    cout << "---------+------------\n";

    for (double eps : epsilons) {
        double pi = Pi(eps);
        cout << fixed << setprecision(6) << eps << "  | " << pi << endl;
    }

    return 0;
}

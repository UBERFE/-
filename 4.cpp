#include <iostream>
#include <iomanip> 
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); 

    double K, M, S;
    cout << "Введите цену за 1 кг:\n";
    cout << "Карамель (руб.): ";
    cin >> K;
    cout << "Мармелад (руб.): ";
    cin >> M;
    cout << "Шоколад (руб.): ";
    cin >> S;
    
    cout << "\nВес (г) | Карамель | Мармелад | Шоколад\n";
    cout << "--------+----------+----------+---------\n";
    
    for (int weight = 100; weight <= 1000; weight += 100) {
        double weight_kg = weight / 1000.0; 
        double cost_K = K * weight_kg;
        double cost_M = M * weight_kg;
        double cost_S = S * weight_kg;
        
        cout << setw(7) << weight << " | "
             << fixed << setprecision(2) << setw(8) << cost_K << " | "
             << setw(8) << cost_M << " | "
             << setw(7) << cost_S << endl;
    }

    return 0;
}

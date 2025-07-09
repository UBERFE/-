#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <map>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ifstream fin;
    ofstream fout;
    fin.open("F1.txt");
    fout.open("F2.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Не получилось открыть файл" << endl;
        return 1;
    }

    string line;
    map<char, int> bukvi;

    while (!fin.eof()) {
        getline(fin, line);

        for (int i = 0; i < line.length(); i++) {
            char c = line[i];

            if (c >= 'A' && c <= 'Z') {
                c = c + 32;
            }

            if ((c >= 'a' && c <= 'z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
                bukvi[c]++;
            }
        }
    }

    const int SIZE = 1000;
    char symbols[SIZE];
    int counts[SIZE];
    int n = 0;

    for (auto it = bukvi.begin(); it != bukvi.end(); it++) {
        symbols[n] = it->first;
        counts[n] = it->second;
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                int tempCount = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = tempCount;

                char tempChar = symbols[j];
                symbols[j] = symbols[j + 1];
                symbols[j + 1] = tempChar;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fout << symbols[i] << " - " << counts[i] << endl;
        cout << symbols[i] << " - " << counts[i] << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

char* findLastWord(char str[]) {
    int len = strlen(str);
    while (len > 0 && str[len - 1] == ' ') {
        len--;
    }
    if (len == 0) {
        return nullptr;
    }
    int end = len - 1;
    int start = end;
    while (start >= 0 && str[start] != ' ') {
        start--;
    }
    return &str[start + 1];
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char input[256];
    cout << "Введите строку: ";
    cin.getline(input, 256);

    char* lastWord = findLastWord(input);

    if (lastWord) {
        cout << "Последнее слово: " << lastWord << endl;
    } else {
        cout << "Слов не найдено." << endl;
    }

    return 0;
}

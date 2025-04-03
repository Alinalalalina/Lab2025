#include <iostream>
using namespace std;

// Первый способ определения длины строки
int dlinal(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Второй способ определения длины строки (рекурсивный)
int dlina2(char* str) {
    return (*str == '\0') ? 0 : 1 + dlina2(str + 1);
}

// Третий способ определения длины строки (с использованием указателей)
int dlina3(char* str) {
    char* p = str;
    while (*p) p++;
    return p - str;
}

// Функция копирования строк
void kopir(char* dest, char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Функция сравнения строк
void sravn(char* str1, char* str2) {
    int result = 0;
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    result = *(unsigned char*)str1 - *(unsigned char*)str2;
    cout << "Результат сравнения: " << result << endl;
}

// Функция конкатенации строк
void konkat(char* dest, char* src) {
    while (*dest) dest++;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main() {
    char str1[50] = "qwerty";
    char str2[50] = "1234567890";
    char copy[50];

    cout << "Длина str1=" << dlinal(str1) << ", str2=" << dlinal(str2) << endl;
    cout << "Длина str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
    cout << "Длина str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;

    kopir(copy, str1);
    cout << "Результат копирования: str1= " << copy << ", str2= " << str2 << endl;

    sravn(str1, str2);

    konkat(str1, str2);
    cout << "Результат сцепления: str1= " << str1 << endl;

    return 0;
}
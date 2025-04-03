#include <iostream>

using namespace std;

// Функция для вычисления степени
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int main() {
    int base, exponent;

    // Ввод числа и степени
    cout << "Введите число: ";
    cin >> base;
    cout << "Введите степень: ";
    cin >> exponent;

    // Вычисление и вывод результата
    int result = power(base, exponent);
    cout << base << " в степени " << exponent << " = " << result << endl;

    return 0;
}